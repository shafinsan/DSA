#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int findUnion(vector<int>& a, vector<int>& b)
{
    int maxValue=1e5+1;
    vector<int>fre(maxValue,0);
    for(int i=0; i<a.size(); i++)
    {
        fre[a[i]++];
    }
    for(int i=0; i<b.size(); i++)
    {
        fre[b[i]++];
    }
    int count=0;
    for(int i=0; i<b.size(); i++)
    {
        if(fre[i]!=0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cout<<"Enter the first array :";
    cin>>n;
    vector<int> a;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }

    cout<<"Enter the second array :";
    int m;
    cin>>m;
    vector<int> b;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        b.push_back(x);
    }

    for(auto i:a)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:b)
    {
        cout<<i<<" ";
    }
    return 0;
}
