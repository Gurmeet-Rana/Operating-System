/* More formally, given an array of n integers, prices, where prices[i] denotes the price of the 
product sold in the ith cubicle. The array prices are in non-decreasing order (i.e., the 
price[i]≤price[i+1]), and q queries need to be processed. For each query, two integers are given: 
pos: Alex’s initial position  
amount: the amount of money Alex has  
Alex needs to visit each cubicle from number pos to n, purchasing at most one product from 
each cubicle. For each query, the goal is to find the maximum number of products that Alex can 
buy */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> findAnswer(vector<int> &arr,vector<vector<int>> &queries,int q)
{
    vector<int> ans(q,0);

    vector<int> prefixSum(arr.size(),0);
    prefixSum[0]=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        prefixSum[i]=prefixSum[i-1]+arr[i];
    }
    
    for(int i=0;i<q;i++)
    {
        int pos=queries[i][0],amt=queries[i][1];
        pos--;
        int val=amt+((pos==0)?0:prefixSum[pos-1]); 
        int left=pos,right=arr.size()-1;
        int res=pos;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(prefixSum[mid]<=val)
            {
                res=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        } 
        ans[i]=res-pos+1;
    }

    return ans;
}
int main()
{
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    vector<int> arr;
    cout<<"Enter the values in the array : "<<endl;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    int q;
    cout<<"Enter the number of queries : "<<endl;
    cin>>q;
    vector<vector<int>> queries(q,vector<int>(2,-1));
    cout<<"Enter the queries : "<<endl;
    for(int i=0;i<q;i++)
    {
        int pos,amt;
        cin>>pos;
        cin>>amt;
        queries[i]={pos,amt};
    }
    vector<int> ans=findAnswer(arr,queries,q);
    cout<<"ANSWER : "<<endl;
    for(int i=0;i<q;i++)
    {
        cout<<ans[i]<<endl;
    }


    return 0;
}