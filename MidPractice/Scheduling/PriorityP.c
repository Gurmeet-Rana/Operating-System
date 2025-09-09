#include<stdio.h>
#include<stdlib.h>
typedef struct Process
{
    int AT,BT,CT,ST,TAT,WT,p;
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
            
        }
    }

    
}