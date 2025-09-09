#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int kDiffPairs(vector < int > & arr, int n, int k) {
    unordered_map<int,int> mp;
    int ans=0;
    set<int> st(arr.begin(),arr.end()); //5 3
//2 6 5 2 3
    for(auto &ele:st)
    {
        cout<<ele<<" ";
        if(mp.find(ele-k)!=mp.end())
        {             
            ans++;
        }
        mp[ele]++;
    }
    return ans;
    // 0 0 0  
}
int main()
{
    int n;
    cout<<"Enter the number of entries"<<endl;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    
    int k;
    cout<<"Enter the value of k : "<<endl;
    cin>>k;
    cout<<"Answer - "<<kDiffPairs(v,n,k);
    return 0;
}