#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>V[2];
    for(int i=0; i<2; i++)
    {
        int x;
        cout<<"give me the vector length index of "<<i+1<<" :";
        cin>>x;
        cout<<"give me the values :";
        for(int j=0; j<x; j++)
        {
            int y;
            cin>>y;
            V[i].push_back(y);
        }
    }

    for(int i=0; i<2; i++)
    {
        vector<int>::iterator it;
        for(it=V[i].begin(); it!=V[i].end(); it++)
        {
            cout<<(*it)<<" ";
        }
    }
    return 0;
}
