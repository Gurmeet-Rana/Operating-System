#include<stdio.h>
#include<stdlib.h>
typedef struct Process
{
    int AT,BT,CT,ST,TAT,WT,completed,RT;
}Process;
void main()
{
    int n;
    printf("Enter the number of processes : \n");
    scanf("%d",&n);
    Process*arr=(Process*)malloc(sizeof(Process)*n);
    for(int i=0;i<n;i++)
    {
        Process p;
        p.completed=0;
        printf("Enter the Arrival Time : \n");
        scanf("%d",&p.AT);
        printf("Enter the Burst Time :\n");
        scanf("%d",&p.BT);
        p.RT=p.BT;
        arr[i]=p;
    }
    int processFinished=0,totalTAT=0,totalWT=0;
    printf("-15s %-15s %-15s %-15s %-15s %-15s %-15s\n","Process","ArrivalTime","BurstTime","StartTime",
    "CompletionTime","TurnAroundTime","WaitingTime");
    int time=0; 
    while(processFinished<n)
    {
        int pid=-1,shortestNow=1e9,shortestAT=1e9;
        for(int i=0;i<n;i++)
        {
            if(arr[i].completed==1 || arr[i].AT>time) continue;
            if(arr[i].RT<shortestNow || (arr[i].RT==shortestNow && arr[i].AT<shortestAT) || (arr[i].RT==shortestNow && arr[i].AT==shortestAT && pid>i))
            {
                pid=i;
                shortestNow=arr[i].RT;
                shortestAT=arr[i].AT;
            }
        }
        if(pid==-1)
        {
            time++;
        }
        else{
            if(arr[pid].RT==arr[pid].BT)
            {
                arr[pid].ST=time;
                arr[pid].RT--;
            }
            else{                
                arr[pid].RT--;
                if(arr[pid].RT==0)
                {
                    arr[pid].completed++;
                    processFinished++;
                    arr[pid].CT=time;
                    arr[pid].TAT=arr[pid].CT-arr[pid].AT;
                    arr[pid].WT=arr[pid].TAT-arr[pid].BT;
                    printf("-15d %-15d %-15d %-15d %-15d %-15d %-15d\n",pid,arr[pid].AT,arr[pid].BT,arr[pid].ST,
    arr[pid].CT,arr[pid].TAT,arr[pid].WT);

                }
            }
            time++;
        }
    }
}