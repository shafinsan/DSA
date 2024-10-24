#include <iostream>
#include<bits/stdc++.h>
using namespace std;



void Display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}

int Partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<=r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[r]);
    return i;
}

void Quick_Sort(int arr[],int l,int r){
    if(r>l){
        int p=Partition(arr,l,r);
        Quick_Sort(arr,l,p-1);
        Quick_Sort(arr,p+1,r);
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
    Quick_Sort(arr,0,n-1);
    Display(arr,n);
    return 0;
}
