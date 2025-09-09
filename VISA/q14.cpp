/*
Given the number of nodes and the number of edges connecting these nodes, arrange these 
edges such that maximum number of nodes are strongly connected. Return the number of 
nodes that could be strongly connected. [Hint:- To make first node strongly connected you need 
n-1 edges for second you need n-2 and so on. i.e edges – (n-1) – (n-2) - ... - (n-k) >= 0, then largest 
k possible is the answer) 
*/
#include<iostream>
using namespace std;
int main()
{
    int N,E;
    cout<<"Enter the number of nodes "<<endl;
    cin>>N;
    cout<<"Enter the number of edges "<<endl;
    cin>>E;
    int avl=E;
    int req=0;
    int ans=0;
    int k=1;
    while((avl-req)>0)
    {
        req=(N-k);
        avl-=req;
        k++;
    }
    cout<<"Maximum Number of nodes that could be strongly connected = "<<k<<endl;
    return 0;
}