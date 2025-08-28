#include<stdio.h>
#include<stdlib.h>
typedef struct process 
{
    int pid,AT,BT,WT,TAT,CT,ST;
}process;

void swap(int *ptr1,int *ptr2)
{
    int temp=*ptr2;
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
            swap(&arr[i].AT,&arr[j].AT);
        }
        j++;
    }
    if(i+1!=high)
    {
        swap(&arr[i].AT,&arr[high].AT);
    }
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

    printf("ProcessId \t ArrivalTime \t BurstTime \t StartTime \t CompletionTime \t TurnAroundTime \t WaitingTime \n");
    
    for(int i=0;i<n;i++)
    {
        arr[i].ST=time;
        time+=arr[i].BT;
        arr[i].CT=time;
        arr[i].TAT=arr[i].BT-arr[i].AT;
        arr[i].WT=arr[i].TAT-arr[i].BT;
        printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \n",arr[i].pid,arr[i].AT,arr[i].BT,arr[i].ST,arr[i].CT,arr[i].TAT,arr[i].WT);
    }

    

    return 0;
}
