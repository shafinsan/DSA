#include <iostream>
#include <vector>
using namespace std;

class twoStacks {
public:
    int *arr;
    int top1;
    int top2;
    int s;

    // Default constructor with array size 100
    twoStacks() {
        this->s = 100;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // Check if space is available
    bool isValid() {
        return top2 - top1 > 1;
    }

    // Push into stack1
    void push1(int x) {
        if (isValid()) {
            top1++;
            arr[top1] = x;
        }
    }

    // Push into stack2
    void push2(int x) {
        if (isValid()) {
            top2--;
            arr[top2] = x;
        }
    }

    // Pop from stack1
    int pop1() {
        if (top1 == -1) {
            return -1;
        }
        int ans = arr[top1];
        top1--;
        return ans;
    }

    // Pop from stack2
    int pop2() {
        if (top2 == s) {
            return -1;
        }
        int ans = arr[top2];
        top2++;
        return ans;
    }

    // Destructor to free allocated memory
    ~twoStacks() {
        delete[] arr;
    }
};

int main() {
    twoStacks ts;  // Default size 100

    // Sample sequence: push1(2), push1(3), push2(4), pop1(), pop2(), pop2()
    ts.push1(2);
    ts.push1(3);
    ts.push2(4);

    vector<int> output;
    output.push_back(ts.pop1());  // Should be 3
    output.push_back(ts.pop2());  // Should be 4
    output.push_back(ts.pop2());  // Should be -1 (stack2 is empty)

    cout << "Output: ";
    for (int x : output) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
