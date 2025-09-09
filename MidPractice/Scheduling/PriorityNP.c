#include<stdio.h>
#include<stdlib.h>
typedef struct Process
{
    int AT,BT,WT,ST,CT,TAT,p,completed;
}Process;
void main()
{
    int n;
    printf("Enter the number of Processes : \n");
    scanf("%d",&n);
    Process*arr=(Process*)malloc(sizeof(Process)*n);
    for(int i=0;i<n;i++)
    {
        Process p;
        printf("Enter the Arrival Time : \n");
        scanf("%d",&p.AT);
        printf("Enter the Burst Time : \n");
        scanf("%d",&p.BT);
        printf("Enter the Priority : \n");
        scanf("%d",&p.p);
        p.completed=0;
        arr[i]=p;
    }
    int processFinished=0,totalTAT=0,totalWT=0;
    printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s \n","Process","ArrivalTime","BurstTime","Priority","CompletionTime","TurnAroundTime","WaitingTime");
    int time=0;

    while(processFinished<n)
    {
        int pid=-1,maxPriority=-1,earliest=1e9;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i].completed==1 || (arr[i].AT>time)) continue;
            if(arr[i].p>maxPriority || (arr[i].p==maxPriority && arr[i].AT<earliest) || (arr[i].p==maxPriority && arr[i].AT==earliest && pid>i))
            {
                maxPriority=arr[i].p;
                pid=i;
                earliest=arr[i].AT;
            }
        }
        if(pid==-1)
        {
            time++;
        }
        else{
            arr[pid].ST=time;
            time+=arr[pid].BT;
            arr[pid].CT=time;
            arr[pid].TAT=arr[pid].CT-arr[pid].AT;
            arr[pid].WT=arr[pid].TAT-arr[pid].BT;
            printf("%-15d %-15d %-15d %-15d %-15d %-15d %-15d\n",pid,arr[pid].AT,arr[pid].BT,arr[pid].p,arr[pid].CT,arr[pid].TAT,arr[pid].WT);

            processFinished++;
            arr[pid].completed=1;

        }

        
    }

}