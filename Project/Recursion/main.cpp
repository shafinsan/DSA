#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// Quick Sort Functions
int pivotElement(int starting, int ending, vector<int>& arr) {
    int i = starting;
    int j = starting - 1;
    int pivot = arr[ending];
    while (i < ending) {
        if (arr[i] > pivot) i++;
        else {
            j++;
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[j + 1], arr[ending]);
    return j + 1;
}

void quickSort(int starting, int ending, vector<int>& arr) {
    if (starting < ending) {
        int p = pivotElement(starting, ending, arr);
        quickSort(starting, p - 1, arr);
        quickSort(p + 1, ending, arr);
    }
}

// Subset and Subsequence Functions
void subsets(int i, vector<int> output, vector<vector<int>>& ans, vector<int> arr) {
    if (i >= arr.size()) {
        ans.push_back(output);
        return;
    }
    subsets(i + 1, output, ans, arr);
    output.push_back(arr[i]);
    subsets(i + 1, output, ans, arr);
}

void subsequence(int i, string output, vector<string>& ans, vector<string> str) {
    if (i >= str.size()) {
        ans.push_back(output);
        return;
    }
    subsequence(i + 1, output, ans, str);
    output += str[i];
    subsequence(i + 1, output, ans, str);
}

// Recursive Functions
int countOfNumber(int number) {
    return (number == 0) ? 0 : number % 10 + countOfNumber(number / 10);
}

int countOfNStire(int x) {
    return (x == 0) ? 1 : (x < 0) ? 0 : countOfNStire(x - 1) + countOfNStire(x - 2);
}

int fib(int x) {
    return (x == 0) ? 0 : (x == 1) ? 1 : fib(x - 1) + fib(x - 2);
}

int myPow(int value) {
    return (value == 0) ? 1 : 2 * myPow(value - 1);
}

bool linerSearch(int s, int target, int *arr) {
    return (s < 0) ? false : (arr[0] == target) ? true : linerSearch(s - 1, target, arr + 1);
}

int arraySum(int s, int *arr) {
    return (s < 0) ? 0 : arr[0] + arraySum(s - 1, arr + 1);
}

bool IsSorted(int s, int *arr) {
    return (s == 0) ? true : (arr[0] > arr[1]) ? false : IsSorted(s - 1, arr + 1);
}

bool binarySearch(int s, int e, int *arr, int target) {
    return (s > e) ? false : (arr[s + (e - s) / 2] == target) ? true
           : (arr[s + (e - s) / 2] < target) ? binarySearch((s + (e - s) / 2) + 1, e, arr, target)
           : binarySearch(s, (s + (e - s) / 2) - 1, arr, target);
}

void reverseString(int i, string &str) {
    if (i >= str.size() / 2) return;
    swap(str[i], str[str.size() - 1 - i]);
    reverseString(i + 1, str);
}

bool isPalindom(int i, string &str) {
    return (i >= str.size() / 2) ? true : (str[i] != str[str.size() - 1 - i]) ? false : isPalindom(i + 1, str);
}

int Pow(int a, int b) {
    return (b == 0) ? 1 : (b == 1) ? a : (b % 2 == 0) ? Pow(a, b / 2) * Pow(a, b / 2) : a * Pow(a, b / 2) * Pow(a, b / 2);
}

void bubbleSort(int mySize, int *arr) {
    if (mySize <= 0) return;
    for (int i = 0; i < mySize; i++) {
        if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
    }
    bubbleSort(mySize - 1, arr);
}

// Keypad and Permutation Functions
void keyPad(int i, string keypadMapping[], string out, vector<string>& ans, string st) {
    if (i >= st.size()) {
        ans.push_back(out);
        return;
    }
    int index = st[i] - '0';
    string mapping = keypadMapping[index];
    if (index < 2 || index > 9) {
        ans.push_back("0,1 and values greater than 9 are undefined");
        return;
    }
    for (int j = 0; j < mapping.size(); j++) {
        out.push_back(mapping[j]);
        keyPad(i + 1, keypadMapping, out, ans, st);
        out.pop_back();
    }
}

void stringPermutation(int i, string st1, vector<string>& ans1) {
    if (i >= st1.size()) {
        ans1.push_back(st1);
        return;
    }
    for (int j = i; j < st1.size(); j++) {
        swap(st1[i], st1[j]);
        stringPermutation(i + 1, st1, ans1);
        swap(st1[i], st1[j]);
    }
}

// Maze Path Finding Functions
bool isSafe(int x, int y, int n, vector<vector<int>> &visited, vector<vector<int>> mat) {
    return (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && mat[x][y] == 1);
}

void solution(int x, int y, int n, string &path, vector<vector<int>> &visited,
              vector<vector<int>> mat, vector<string> &ans) {
    if (x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    if (isSafe(x+1, y, n, visited, mat)) {
        path.push_back('D');
        solution(x+1, y, n, path, visited, mat, ans);
        path.pop_back();
    }
    if (isSafe(x, y-1, n, visited, mat)) {
        path.push_back('L');
        solution(x, y-1, n, path, visited, mat, ans);
        path.pop_back();
    }
    if (isSafe(x, y+1, n, visited, mat)) {
        path.push_back('R');
        solution(x, y+1, n, path, visited, mat, ans);
        path.pop_back();
    }
    if (isSafe(x-1, y, n, visited, mat)) {
        path.push_back('U');
        solution(x-1, y, n, path, visited, mat, ans);
        path.pop_back();
    }
    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &mat) {
    vector<string> ans;
    if (mat[0][0] == 0) return ans;
    int n = mat.size();
    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";
    solution(0, 0, n, path, visited, mat, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int choice;
    vector<int> arr;
    bool arrayFilled = false;
    char continueChoice;
    string keypadMapping[] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter array elements\n";
        cout << "2. Perform Quick Sort\n";
        cout << "3. Generate Subsets\n";
        cout << "4. Generate Subsequences\n";
        cout << "5. Array operations (sort check, sum, search)\n";
        cout << "6. Calculate power of 2\n";
        cout << "7. Calculate Fibonacci number\n";
        cout << "8. Count ways to climb stairs\n";
        cout << "9. Count digits in a number\n";
        cout << "10. String operations (palindrome check, reverse)\n";
        cout << "11. Calculate any power\n";
        cout << "12. Bubble sort array\n";
        cout << "13. Generate keypad combinations\n";
        cout << "14. Generate string permutations\n";
        cout << "15. Find maze paths\n";
        cout << "16. Exit\n";
        cout << "Enter your choice (1-16): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "Enter the size of array: ";
                cin >> n;
                if (n <= 0) {
                    cout << "Please enter a valid size (>0)\n";
                    break;
                }
                arr.clear();
                cout << "Enter " << n << " elements:\n";
                for (int i = 0; i < n; i++) {
                    int x;
                    cout << "Element " << i + 1 << ": ";
                    cin >> x;
                    arr.push_back(x);
                }
                arrayFilled = true;
                cout << "Array entered successfully!\n";
                break;
            }
            case 2: {
                if (!arrayFilled) {
                    cout << "Please enter array elements first (Choice 1)\n";
                    break;
                }
                vector<int> temp = arr;
                cout << "Before quick sort: ";
                for (auto i : temp) cout << i << " ";
                cout << endl;
                quickSort(0, temp.size() - 1, temp);
                cout << "After quick sort: ";
                for (auto i : temp) cout << i << " ";
                cout << endl;
                break;
            }
            case 3: {
                if (!arrayFilled) {
                    cout << "Please enter array elements first (Choice 1)\n";
                    break;
                }
                vector<vector<int>> ans;
                vector<int> output;
                subsets(0, output, ans, arr);
                cout << "Subsets:\n";
                for (const auto& subset : ans) {
                    cout << "{ ";
                    for (int num : subset) cout << num << " ";
                    cout << "}\n";
                }
                break;
            }
            case 4: {
                int strSize;
                cout << "Enter the number of strings: ";
                cin >> strSize;
                if (strSize <= 0) {
                    cout << "Please enter a valid size (>0)\n";
                    break;
                }
                vector<string> str(strSize);
                cout << "Enter " << strSize << " strings:\n";
                for (int i = 0; i < strSize; i++) {
                    cout << "String " << i + 1 << ": ";
                    cin >> str[i];
                }
                vector<string> ans;
                string output = "";
                subsequence(0, output, ans, str);
                cout << "Subsequences:\n";
                for (const auto& seq : ans) cout << "{ " << seq << " }\n";
                break;
            }
            case 5: {
                int n;
                cout << "Enter array size: ";
                cin >> n;
                if (n <= 0) {
                    cout << "Please enter a valid size (>0)\n";
                    break;
                }
                int tempArr[n];
                cout << "Enter " << n << " numbers: ";
                for (int i = 0; i < n; i++) cin >> tempArr[i];
                bool check = IsSorted(n-1, tempArr);
                cout << (check ? "Sorted" : "Not sorted") << endl;
                if (check) {
                    cout << "Sum of the array: " << arraySum(n-1, tempArr) << endl;
                    int target;
                    cout << "Enter value to search: ";
                    cin >> target;
                    cout << "Linear Search: " << (linerSearch(n-1, target, tempArr) ? "Present" : "Not present") << endl;
                    cout << "Binary Search: " << (binarySearch(0, n-1, tempArr, target) ? "Present" : "Not present") << endl;
                }
                break;
            }
            case 6: {
                int value;
                cout << "Enter power value: ";
                cin >> value;
                cout << "2^" << value << " = " << myPow(value) << endl;
                break;
            }
            case 7: {
                int value;
                cout << "Enter position for Fibonacci: ";
                cin >> value;
                cout << "Fibonacci(" << value << ") = " << fib(value) << endl;
                break;
            }
            case 8: {
                int value;
                cout << "Enter number of stairs: ";
                cin >> value;
                cout << "Ways to climb " << value << " stairs: " << countOfNStire(value) << endl;
                break;
            }
            case 9: {
                int value;
                cout << "Enter a number: ";
                cin >> value;
                cout << "Digits in " << value << ": " << countOfNumber(value) << endl;
                break;
            }
            case 10: {
                string str;
                cout << "Enter a string: ";
                cin >> str;
                cout << "Is Palindrome: " << (isPalindom(0, str) ? "Yes" : "No") << endl;
                string temp = str;
                reverseString(0, temp);
                cout << "Reversed string: " << temp << endl;
                break;
            }
            case 11: {
                int base, exp;
                cout << "Enter base: ";
                cin >> base;
                cout << "Enter exponent: ";
                cin >> exp;
                cout << base << "^" << exp << " = " << Pow(base, exp) << endl;
                break;
            }
            case 12: {
                int n;
                cout << "Enter array size: ";
                cin >> n;
                if (n <= 0) {
                    cout << "Please enter a valid size (>0)\n";
                    break;
                }
                int tempArr[n];
                cout << "Enter " << n << " numbers: ";
                for (int i = 0; i < n; i++) cin >> tempArr[i];
                bubbleSort(n-1, tempArr);
                cout << "Sorted array: ";
                for (int i = 0; i < n; i++) cout << tempArr[i] << " ";
                cout << endl;
                break;
            }
            case 13: {
                string st;
                cout << "Enter digits (2-9): ";
                cin >> st;
                vector<string> ans;
                string out;
                keyPad(0, keypadMapping, out, ans, st);
                cout << "Keypad combinations:\n";
                for (auto i : ans) cout << i << endl;
                break;
            }
            case 14: {
                string st1;
                cout << "Enter a string: ";
                cin >> st1;
                vector<string> ans1;
                stringPermutation(0, st1, ans1);
                cout << "String permutations:\n";
                for (auto i : ans1) cout << i << endl;
                break;
            }
            case 15: {
                int n;
                cout << "Enter maze size (n x n): ";
                cin >> n;
                if (n <= 0) {
                    cout << "Please enter a positive size\n";
                    break;
                }
                vector<vector<int>> mat(n, vector<int>(n));
                cout << "Enter matrix elements (0 or 1):\n";
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        cin >> mat[i][j];
                        if (mat[i][j] != 0 && mat[i][j] != 1) {
                            cout << "Invalid input! Use only 0 or 1\n";
                            return 1;
                        }
                    }
                }
                cout << "\nInput Matrix:\n";
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) cout << mat[i][j] << " ";
                    cout << endl;
                }
                vector<string> result = findPath(mat);
                cout << "\nResult:\n";
                if (result.empty()) cout << "No path exists\n";
                else {
                    cout << "Possible paths:\n";
                    for (string path : result) cout << path << " ";
                    cout << endl;
                }
                break;
            }
            case 16: {
                cout << "Exiting program...\n";
                break;
            }
            default: {
                cout << "Invalid choice! Please enter a number between 1 and 16\n";
                break;
            }
        }

        if (choice != 16) {
            cout << "\nContinue? (y/n): ";
            cin >> continueChoice;
        } else {
            continueChoice = 'n';
        }
    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}
