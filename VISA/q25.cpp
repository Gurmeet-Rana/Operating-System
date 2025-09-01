/* 25.Imagine that you are standing at the starting point of a straight street and trying to reach the end of the street. This street is represented by a number line starting at 0 and ending at finish (finish > 0). There are electric scooters scattered along the street to help you get to the end. Specifically, the scooters are represented by an array scooters, with scooters[i] representing the location of the ith scooter. Each scooter can travel upto 10 points along the number line before its battery is fully discharged and it cannot go further. For example, if a scooter is at point 5, it can travel to points 5,6,7,8 … upto point 15 (inclusive), but it cannot get to the point q6 or further.  
To get to the end point of the street, you must use the following algorithm:- 
1. From the current position, travel to the nearest scooter to the right on foot. If there are 
no more scooters available, travel to the end point on foot. 
2. Get on this scooter and use all of its battery/resources to travel as far as you can toward 
the end point. 
3. If you still haven’t reached the end point, repeat this process from step 1. 
Given that you must use the algorithm described above to travel from starting point of the street 0 to the end point of the street finish, your task is to return the total distance that you will travel on scooters. 
NOTE. You are not expected to provide the most optimal solution, but a solution with the time 
complexity not worse than O(scooters.length x finish) will fit within the execution time limit. 
Example :
1. For finish =23 and scooters = [7 ,4, 14], the output should be 19. 4->14 then 14->21 = 19 
2. For finish = 27 and scooters = [15, 7,3,10], the output should be 3->13 and 15-> 25 = 20. 
3. For finish =10 and scooters = [], the output should be 0. 
First line of input is an integer representing finish, next line has n representing the number of scooters and next line contains n integers representing the location of the scooters.  */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int find(vector<int> &scooters,int curr)
{
    int val=scooters[curr]+10;
    //FIND THE RIGHT MOST SCOOTER VALUE THIS OR GREATER 
    int ans=scooters.size()-1;
}
int main()
{
    int n;
    cout<<"Enter the number of scooters : "<<endl;
    cin>>n;   
    vector<int> scooters(n);              
    cout<<"Enter the positions of the scooters : "<<endl;  
    for(int i=0;i<n;i++)
    {    
        cin>>scooters[i];  
    }
    int finish;
    cout<<"Enter the value of finish "<<endl;
    cin>>finish;

    sort(scooters.begin(),scooters.end());
                                            
    int totalWalk=0;

    //FIND THE END SCOOTER WHICH IS GREATER THAN OR EQUAL TO CURRENT 
    int currScooter=-1;
     // 4 7 14 20 
    while(currScooter<n)
    {
        int i=find(scooters,currScooter);
        if(currScooter!=-1)
        {
            totalWalk+=scooters[i]-scooters[currScooter];
            currScooter=i;
        }
        else
        {
            currScooter=i;
        }
    }

    if(currScooter+10<=finish)
    {
        totalWalk+=finish-currScooter;
    }
    
    cout<<"Answer : "<<totalWalk<<endl;
    return 0;
}