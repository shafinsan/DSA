#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int combine(int l,int r,int mid,vector<int> &arr)
{
    int i=l;
    int j=mid+1;
    vector<int> temp;
    int ct=0;
    while(i<=mid && j<=r)
    {
        if(arr[i]>arr[j])
        {
            temp.push_back(arr[j]);
            ct+=mid-i+1;
            j++;
        }
        else
        {
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=r)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for(int z=0; z<temp.size(); z++)
    {
        arr[z+l]=temp[z];
    }
    return ct;

}


int margeSort(int l,int r,vector<int> &arr)
{
    int ct=0;
    if(l<r)
    {
        int mid=l+(r-l)/2;
        ct+=margeSort(l,mid,arr);
        ct+=margeSort(mid+1,r,arr);
        ct+=combine(l,r,mid,arr);
    }
    return ct;

}

int main()
{
    vector<int> arr;
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ct=margeSort(0,arr.size()-1,arr);
    cout<<"Count Inversions :"<<ct;

    return 0;
}
