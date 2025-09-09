#include<stdio.h>
#include<stdlib.h>
typedef struct Process
{
    int AT,BT,CT,ST,TAT,WT;
}Process;
void swap(Process *p1,Process *p2)
{
    Process temp=*p1;
    *p1=*p2;
    *p2=temp;
}
int Partition(Process*arr,int low,int high)
{
    int key=arr[high].AT;

    int i=low-1,j=low;
    while(j<high)
    {
        if(arr[j].AT<key)
        {
            i++;
            swap(&arr[j],&arr[i]);
        }
        j++;
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quickSort(Process*arr,int low,int high)
{
    if(low<high)
    {   
        int pivot=Partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
    return;
}
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
        p.WT=0;
        arr[i]=p;
    }
    quickSort(arr,0,n-1);

    int time=0;
    for(int i=0;i<n;i++)
    {
        if(time<arr[i].AT)
        {
            time=arr[i].AT;
        }
        else{
            arr[i].ST=time;
            time+=arr[i].BT;
            arr[i].CT=time;
            arr[i].TAT=arr[i].CT-arr[i].AT;
            arr[i].WT=arr[i].TAT-arr[i].BT;
        }
    }

    //SORTED 
    printf("%-15s %-15s %-15s %-15s %-15s %-15s","Arrival Time","Burst Time","Start Time","Completion Time","TurnAroundTime","WaitingTime");
    for(int i=0;i<n;i++)
    {
        printf("%-15s %-15s %-15s %-15s %-15s %-15s",arr[i].AT,arr[i].BT,arr[i].ST,arr[i].CT,arr[i].TAT,arr[i].WT);
    }

 
}