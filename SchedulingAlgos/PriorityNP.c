#include<stdio.h>
#include<stdlib.h>
typedef struct process 
{
    int pid,AT,BT,CT,ST,TAT,WT,p;
}process;
int main()
{
    int n;
    printf("Enter the number of processes :\n" );
    scanf("%d",&n);
    process * arr;
    arr=(process*)malloc(sizeof(process)*n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the details of the %d th process : \n",i+1);
        process p ;
        p.pid=i;
        printf("Enter the priority : \n");
        scanf("%d",&p.p);
        printf("Enter the Arrival Time : \n");
        scanf("%d",&p.AT);
        printf("Enter the Burst Time : \n");
        scanf("%d",&p.BT);
        arr[i]=p;
    }

    printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s \n","ProcessID", "Priority","ArrivalTime","BurstTime","StartTime","CompletionTime","TurnAroundTime","WaitingTime");
    int processFinished=0;
    int time=0;
    int isFinished[n];
    for(int i=0;i<n;i++)
    {
        isFinished[i]=0;
    }

    while (processFinished<n)
    {
        int pid=-1,earliest=1e9,maxPriority=-1;
        for(int i=0;i<n;i++)
        {
            if(isFinished[i] || arr[i].AT>time) continue;
            if(arr[i].p>maxPriority || (arr[i].p==maxPriority && arr[i].AT<earliest) || ( arr[i].p==maxPriority && arr[i].AT==earliest && arr[i].pid<pid))
            {
                maxPriority=arr[i].p;
                earliest=arr[i].AT;
                pid=arr[i].pid;
            }
        }
        if(pid!=-1)
        {
            arr[pid].ST=time;
            time+=arr[pid].BT;
            arr[pid].CT=time;
            arr[pid].TAT=arr[pid].CT-arr[pid].AT;
            arr[pid].WT=arr[pid].TAT-arr[pid].BT;
            printf("%-15d %-15d %-15d %-15d %-15d %-15d %-15d %-15d\n",arr[pid].pid, arr[pid].p,arr[pid].AT,arr[pid].BT,arr[pid].ST,arr[pid].CT,arr[pid].TAT,arr[pid].WT);

            isFinished[pid]=1;
            processFinished++;
        }
        else
        {
            time++;
        }
    }
    
    return 0 ; 
}