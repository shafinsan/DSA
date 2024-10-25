#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cout<<"Enter the size of array :";
    cin>>N;
    vector<vector<int>>arr;
    for(int i=0;i<N;i++){
        int x, y;
        cout << "Enter the first value: ";
        cin >> x;
        cout << "Enter the second value: ";
        cin >> y;
        arr.push_back({x,y});
    }
    for(auto i:arr){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"back :";
    cout<<arr.back()[1];
    cout<<"After sorting"<<endl;

    sort(arr.begin(),arr.end());
     for(auto i:arr){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<"After pop back"<<endl;
    arr.pop_back();
     for(auto i:arr){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
