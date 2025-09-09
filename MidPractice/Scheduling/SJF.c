#include<stdio.h>
#include<stdlib.h>
typedef struct Process
{
    int AT,BT,WT,CT,ST,TAT,completed;
}Process;
void main()
{
    int n;
    printf("Enter the number of Processes : \n");
    scanf("%d",&n);
    Process*arr=(Process*)malloc(sizeof(Process)*n);

    for(int i=0;i<n;i++)
    {
        Process p ; 
        p.completed=0;
        printf("Enter the Arrival Time : \n");
        scanf("%d",&p.AT);
        printf("Enter the Burst Time : \n");
        scanf("%d",&p.BT);
        arr[i]=p;
    }

    int processFinished=0,totalTAT=0,totalWT=0;
    int time=0;
    printf("%-15s %-15s %-15s\n","Process ID","Arrival Time","Burst Time");
    while(processFinished<n)
    {
        int shortestJob=-1,shortest=1e9,shortestAT=1e9;
        for(int i=0;i<n;i++)
        {
            if(arr[i].completed==1 || arr[i].AT>time) continue;
            if( arr[i].BT < shortest || (arr[i].BT==shortest && arr[i].AT<shortestAT) )
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
            processFinished++;
            arr[shortestJob].completed=1;
            printf("%-15d %-15d %-15d\n",shortestJob,arr[shortestJob].AT,arr[shortestJob].BT);
        }
        else
        {
            time++;
        }
    }
}