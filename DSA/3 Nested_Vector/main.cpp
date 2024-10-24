#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void  printVector(vector<int>&n)
{
    cout<<"Size :"<<n.size()<<endl;
    for(int j=0; j<n.size(); j++)
    {
        cout<<n[j]<<" ";
    }
    cout<<endl;
}


int main()
{
    int N;
    cout<<"Enter the size of vector";
    cin>>N;
    vector<int>V[N];
    for(int i=0; i<N; i++)
    {
        int x;
        cout<<"Give me "<<i<<" index size";
        cin>>x;
        cout<<"Give me the value you want to store :";
        for(int j=0; j<x; j++)
        {
            int value;
            cin>>value;
            V[i].push_back(value);
        }
    }
    for(int i=0; i<N; i++)
    {
        printVector(V[i]);
    }


    return 0;
}
