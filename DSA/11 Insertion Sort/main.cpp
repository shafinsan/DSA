#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void insertionSort(vector<int>&arr){
    for(int i=1;i<arr.size();i++){
        int j=i-1;
        int value=arr[i];
        while(j>=0){
            if(arr[j]>value){
                arr[j+1]=arr[j];
            }
            j--;
        }
        arr[j+1]=value;

    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array :";
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    insertionSort(arr);
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}
