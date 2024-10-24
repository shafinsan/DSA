#include <iostream>
using namespace std;

int pivotElement(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

int quickSelect(int arr[],int l,int r,int k){
    if(l<=r){
        int p=pivotElement(arr,l,r);
        if(p+1==k){
            return arr[p];
        }
        if(p+1<k){
            return quickSelect(arr,p+1,r,k);
        }
        if(p+1>k){
            return quickSelect(arr,l,p-1,k);
        }
    }
}



int main()
{
    int n;
    cout<<"Enter the size of array :";
    cin>>n;
    cout<<"Enter the kth element :";
    int k;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int value=quickSelect(arr,0,n-1,k);
    cout<<value;
    return 0;
}
