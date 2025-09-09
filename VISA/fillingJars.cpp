#include<iostream>
#include<vector>
#include<map>
using namespace std;

int findAnswer(vector<vector<int>> &queries,int q,int n)
{   
    map<int,int> mp;
    for(auto &q:queries)
    {
        int a=q[0],b=q[1],k=q[2];
        mp[a]+=k;
        if(b+1<=n)
        {
            mp[b+1]-=k;
        }
    }
    int total=0;
    for(auto &p:mp)
    {
        total+=p.second;
    }
    return total/n;
}
int main()
{
    int n;
    cout<<"Enter the number of Jars : "<<endl;
    cin>>n;
   
    int q;
    cout<<"Enter the number of queries : "<<endl;
    cin>>q;
    vector<vector<int>> queries;
    for(int i=0;i<q;i++)
    {
        int a,b,k;
        cin>>a>>b>>k;
        queries.push_back({a,b,k});
    }
    int avg=findAnswer(queries,q,n);
    cout<<"Answer = "<<avg<<endl;

    return 0;
}