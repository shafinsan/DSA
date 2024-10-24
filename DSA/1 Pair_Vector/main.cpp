#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void printVector(vector<int>n){
    cout<<"size :"<<n.size()<<endl;
    cout<<"............print start............"<<endl;
    for(int i=0;i<n.size();i++){
        cout<<n[i]<<" ";
    }
     cout<<endl<<"............print end............"<<endl;
}


int main()
{
    pair<int,int>p1;
    p1={1,2};
    cout<<p1.first<<" "<<p1.second<<endl;
    pair<int,int>p2[4];
    p2[0]={1,2};
    p2[1]={2,3};
    p2[2]={3,4};
    p2[3]={4,5};
    swap(p2[0],p2[3]);
    cout<<p2[0].first<<" "<<p2[0].second<<endl;
    cout<<"................End of pair................"<<endl;
    vector<int>n;
    for(int i=0;i<5;i++){
        printVector(n);
        int x;
        cin>>x;
        n.push_back(x);
    }
    vector<int>&value=n;
    value[3]=100;
    cout<<endl<<"when i pass the ref here bby"<<endl;
    printVector(n);

    return 0;
}
