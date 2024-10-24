#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void Display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
void BubbleSort(int arr[],int l,int r){
    for(int i=0;i<r;i++){
        for(int j=0;j<r-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

}
int main()
{
    int n;
    cout<<"Enter the size of the array :";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    BubbleSort(arr,0,n-1);
    Display(arr,n);
}
