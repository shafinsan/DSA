#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>>V;
    for(int i=0; i<2; i++)
    {
        int x;
        cout<<"give me the vector length index of "<<i+1<<" :";
        cin>>x;
        cout<<"give me the values :";
        V.push_back(vector<int>());
        for(int j=0; j<x; j++)
        {
            int y;
            cin>>y;
            V[i].push_back(y);
        }
    }

    for(auto i:V)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
