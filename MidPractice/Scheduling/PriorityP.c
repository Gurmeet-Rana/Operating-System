#include<stdio.h>
#include<stdlib.h>
typedef struct Process
{
    int AT,BT,CT,ST,TAT,WT,p,RT;
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
        printf("Enter the Arrival Time :\n");
        scanf("%d",&p.AT);
        printf("Enter the Burst Time : \n");
        scanf("%d",&p.BT);
        printf("Enter the priority : \n");
        scanf("%d",&p.p);

        
        arr[i]=p;
        arr[i].RT=arr[i].BT;
    }
    int time=0;
    int processFinished=0,totalTAT=0,totalWT=0;
    while(processFinished<n)
    {
        int maxPriority=0,pid=-1,earliest=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i].p>maxPriority || (arr[i].p==maxPriority && arr[i].AT<earliest) || (arr[i].p==maxPriority && arr[i].AT==earliest && pid>i ))
            {
                pid=i;
                earliest=arr[i].AT;
                maxPriority=arr[i].p;
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
            }
            else
            {
                arr[pid].RT--;
                if(arr[pid].RT==0)
                {
                    arr[pid].CT=time;
                    arr[pid].TAT=arr[pid].CT-arr[pid].AT;
                    arr[pid].WT=arr[pid].TAT-arr[pid].BT;
                }
            }
        }
    }

    
}