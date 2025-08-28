#include<stdio.h>
#include<stdlib.h>
typedef struct process 
{
    int pid,AT,BT,WT,TAT,CT,ST;
}process;

void swap(process *ptr1,process *ptr2)
{
    process temp=*ptr2;
    *ptr2=*ptr1;
    *ptr1=temp;
}

int Partition(process arr[],int low,int high)
{
    int pivot=arr[high].AT;
    int i=low-1,j=low;
    while(j<high)
    {
        if(arr[j].AT<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
        j++;
    }
    swap(&arr[i+1],&arr[high]);    
    return i+1;
}

void quickSort(process arr[],int low,int high)
{
    if(low<high)
    {
        int pivot=Partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
        return ;
    }

}
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
        printf("Enter the details of the %d th process \n ",i+1);
        printf("Enter the arrival time of this process : \n");
        scanf("%d",&p.AT);
        printf("Enter the Burst Time of this process : \n");
        scanf("%d",&p.BT);
        p.pid=i;
        arr[i]=p;       
    }

    quickSort(arr,0,n-1);

    int time=0;

    printf("%-10s %-12s %-10s %-10s %-15s %-15s %-12s\n",
       "ProcessId", "ArrivalTime", "BurstTime", "StartTime",
       "CompletionTime", "TurnAroundTime", "WaitingTime");

    int totalTAT=0,totalWT=0;
    
    for(int i=0;i<n;i++)
    {
        
        if(time<arr[i].AT)
        {
            time=arr[i].AT;
        }
        arr[i].ST=time;
        time+=arr[i].BT;
        arr[i].CT=time;
        arr[i].TAT=arr[i].CT-arr[i].AT;
        totalTAT+=arr[i].TAT;
        arr[i].WT=arr[i].TAT-arr[i].BT;
        totalWT+=arr[i].WT;
        printf("%-10d %-12d %-10d %-10d %-15d %-15d %-12d\n",arr[i].pid,arr[i].AT,arr[i].BT,arr[i].ST,arr[i].CT,arr[i].TAT,arr[i].WT);
    }
    
    printf("Average TAT %d Average WT %d\n",totalTAT/n,totalWT/n);

    return 0;
}
