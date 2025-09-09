/* 11. Given a string consisting of letters that indicate directions i.e. ‘L’ for left, ‘R’ for right, ‘U’ for, up
 and ‘D’ for down, find the maximum length of string that can be obtained after deleting some characters of 
the string so that we reach the same destination as the 
original string. */

#include<iostream>
#include<string>
using namespace std;
class Solution
{
    public : 
        static int solve(string &input)
        {
            int x=0,y=0;
            int lFrq=0,rFrq=0,uFrq=0,dFrq=0;
            for(auto &ch:input)
            {
                if(ch=='L') lFrq++;
                else if(ch=='R') rFrq++;
                else if(ch=='U') uFrq++;
                else dFrq++;
            }
            int hDist=abs(lFrq-rFrq),vDist=abs(uFrq-dFrq);
            return hDist+vDist;
        }
};
int main()
{
    string str;
    cout<<"Enter the string : "<<endl;
    cin>>str;
    cout<<"Answer - "<<Solution::solve(str)<<endl;
    return 0;
}