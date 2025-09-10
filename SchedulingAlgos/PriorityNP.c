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

   while (processFinished < n) {
        int idx = -1, earliest = 1e9, maxPriority = -1;

        for (int i = 0; i < n; i++) {
            if (isFinished[i] || arr[i].AT > time) continue;

            if (arr[i].p > maxPriority ||
            (arr[i].p == maxPriority && arr[i].AT < earliest) ||
            (arr[i].p == maxPriority && arr[i].AT == earliest && i < idx)) {
                
                maxPriority = arr[i].p;
                earliest = arr[i].AT;
                idx = i;
            }
        }

        if (idx != -1) {
            arr[idx].ST = (time < arr[idx].AT) ? arr[idx].AT : time;
            arr[idx].CT = arr[idx].ST + arr[idx].BT;
            arr[idx].TAT = arr[idx].CT - arr[idx].AT;
            arr[idx].WT = arr[idx].TAT - arr[idx].BT;

            printf("%-15d %-15d %-15d %-15d %-15d %-15d %-15d %-15d\n",
                arr[idx].pid, arr[idx].p, arr[idx].AT, arr[idx].BT,
                arr[idx].ST, arr[idx].CT, arr[idx].TAT, arr[idx].WT);

            isFinished[idx] = 1;
            processFinished++;
            time = arr[idx].CT;
        } else {
            time++;
        }
    }

    
    return 0 ; 
}