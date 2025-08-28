#include<stdio.h>
#include<stdlib.h>
typedef struct process
{
    int pid,AT,BT,CT,ST,TAT,WT;
}process;

int main()
{
    int n;
    printf("Enter the number of processes : \n");
    scanf("%d",&n);

    process *arr;
    arr=(process*)malloc(sizeof(process)*n);
    for(int i=0;i<n;i++)
    {
        process p;
        printf("Enter the details of the %d th process : \n",i+1);
        p.pid=i;
        printf("Enter the Arrival Time : \n");
        scanf("%d",&p.AT);
        printf("Enter the Burst Time : \n");
        scanf("%d",&p.BT);
        arr[i]=p;
    }


    int time=0;
    float totalTAT=0,totalBT=0,totalWT=0;

    printf("%-10s %-12s %-15s %-10s %-15s %-15s %-10s \n","ProcessID","ArrivalTime","BurstTime","StartTime","CompletionTime","WaitingTime","TurnAroundTime");

    int processFinished=0;
    int isFinished[n];
    for(int i=0;i<n;i++) isFinished[i]=0;

    while(processFinished<n)
    {
        int pid=-1,minBT=1e9,earliest=1e9;
        for(int i=0;i<n;i++)
        {
            if(isFinished[i] || arr[i].AT>time) continue;
            
            if(arr[i].BT<minBT || (arr[i].BT==minBT && arr[i].AT<earliest) || (arr[i].BT==minBT && arr[i].AT==earliest && arr[i].pid<pid))
            {
                minBT=arr[i].BT;
                pid=i;
                if(arr[i].AT<earliest)
                {
                    earliest=arr[i].AT;
                }
            }
        }
        if(pid!=-1)
        {
            arr[pid].ST=time;
            time+=arr[pid].BT;
            isFinished[pid]=1;
            processFinished++;
            arr[pid].CT=time;
            arr[pid].TAT=arr[pid].CT-arr[pid].AT;
            arr[pid].WT=arr[pid].TAT-arr[pid].BT;

            totalWT+=arr[pid].WT;
            totalTAT+=arr[pid].TAT;
            
            printf("%-10d %-12d %-15d %-10d %-15d %-15d %-10d \n",arr[pid].pid,arr[pid].AT,arr[pid].BT,arr[pid].ST,arr[pid].CT,arr[pid].WT,arr[pid].TAT);

        }
        else
        {
            time++;
        }
    }

    printf("Average TAT = %f Average WT = %f \n",totalTAT/n,totalWT/n);


    return 0;
}