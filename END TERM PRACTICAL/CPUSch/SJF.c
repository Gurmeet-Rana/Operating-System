#include<stdio.h>
#include<stdlib.h>
typedef struct Process
{
    int AT,BT,CT,ST,TAT,WT;
    int completed;
}Process;
void main()
{
    int n;
    printf("Enter the number of processes : \n");
    scanf("%d",&n);
    Process *arr=(Process*)malloc(sizeof(Process)*n);
    for(int i=0;i<n;i++)
    {
        Process p;
        printf("Enter the ArrivalTime : \n");
        scanf("%d",&p.AT);
        printf("Enter the BurstTime : \n");
        scanf("%d",&p.BT);
        p.CT=p.BT;
        p.ST=p.AT;
        p.TAT=0;
        p.completed=0;
        p.WT=0;
        arr[i]=p;
    }
     
    int time=0;
    int complete=0;
    while(complete<n)
    {
        int shortestJob=-1,shortest=1e9,shortestAT=1e9;
        for(int i=0;i<n;i++)
        {
            if(arr[i].completed==1 || (arr[i].AT>time)) continue;
            if(arr[i].BT<shortest || (arr[i].BT==shortest && arr[i].AT<shortestAT))
            {
                shortest=arr[i].BT;
                shortestJob=i;
                shortestAT=arr[i].AT;
            }
        }
        if(shortestJob!=-1)
        {
            arr[shortestJob].ST=time;
            time+=arr[shortestJob].BT;
            arr[shortestJob].TAT=arr[shortestJob].BT-arr[shortestJob].AT;
            arr[shortestJob].WT=arr[shortestJob].TAT-arr[shortestJob].BT;
            complete++;
            arr[shortestJob].completed=1;
            printf("%-15d %-15d %-15d\n",shortestJob,arr[shortestJob].AT,arr[shortestJob].BT);
        }
        else{
            time++;
        }
    }
 

 
}