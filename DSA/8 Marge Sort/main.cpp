#include <iostream>
#include <bits/stdc++.h>
using namespace std;



void margeArray(vector<int>&arr,int l,int r,int mid){
    vector<int>temp;
    int i=l;
    int j=mid+1;
    while(i<=mid && j<=r){
        if(arr[i]>arr[j]){
            temp.push_back(arr[j]);
            j++;
        }
        else{
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=r){
        temp.push_back(arr[j]);
        j++;
    }
    for(int k=0; k<temp.size();k++){
        arr[k+l]=temp[k];

    }
}
void margeSort(vector<int>&arr,int l,int r){
    if(r > l){
        int mid=l+((r-l)/2);
        margeSort(arr,l,mid);
        margeSort(arr,mid+1,r);
        margeArray(arr,l,r,mid);
    }

}

int main()
{
    int n;
    cout<<"Enter the size of array :";
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    margeSort(arr,0,n-1);

    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}
