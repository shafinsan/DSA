#include <iostream>
#include<bits/stdc++.h>
using namespace std;



int main()
{
    int N;
    cout<<"Enter the size of vector";
    cin>>N;
    vector<vector<int>>V;
    for(int i=0; i<N; i++)
    {
        int x;
        cout<<"Give me "<<i<<" index size";
        cin>>x;
        cout<<"Give me the value you want to store :";
        V.push_back(vector<int>());
        for(int j=0; j<x; j++)
        {
            int value;
            cin>>value;
            V[i].push_back(value);
        }
    }
    V.push_back(vector<int>());
    for(int i=0; i<V.size(); i++)
    {
        cout<<"Size :"<<V[i].size()<<endl;
        for(int j=0; j<V[i].size(); j++)
        {
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
