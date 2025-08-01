#include<stdio.h>
#include<stdlib.h>
typedef struct process{
    int pid,AT,BT,ST,CT,TAT,WT;
}process;
void insertionSort(process *arr,int n)
{
    //INSERTION SORT

    // 1 3 2 4 5 
    for(int j=1;j<n;j++)
    {
        int i=j-1;
        process key=arr[j];
        while(i>=0 && arr[i].AT>key.AT)
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    }

}
int main()
{
    int n;
    printf("Enter the number of processes \n");
    scanf("%d",&n);
    process *arr=(process*)malloc(sizeof(process)*n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the details of %d th process : \n",i+1);
        int at,bt,pid;
        printf("Process ID : \n");
        scanf("%d",&pid);
        printf("Arrival Time : \n");
        scanf("%d",&at);
        printf("Burst Time : \n");
        scanf("%d",&bt);
        process p;
        p.pid=pid;
        p.AT=at;
        p.BT=bt;
        arr[i]=p;         
    }

    insertionSort(arr,n);

    for(int i=0;i<n;i++)
    {
        if(!i)
        {
            arr[i].CT=arr[i].AT+arr[i].BT;
            arr[i].ST=arr[i].AT;
            arr[i].TAT=arr[i].CT-arr[i].AT;
            arr[i].WT=0;
        }
        else{
            arr[i].ST=arr[i-1].CT;
            arr[i].CT=arr[i-1].CT+arr[i].BT;
            arr[i].TAT=arr[i].CT-arr[i].AT;
            arr[i].WT=arr[i].CT-arr[i].ST;             
        }
    }

    printf("PROCESS ID \t ARRIVAL TIME \t BURST TIME \t COMPLETION TIME \t START TIME \t TOTAL TURN AROUND TIME \t WAITING TIME \n ");
    for(int i=0;i<n;i++)
    {
        printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t \t %d \n",arr[i].pid,arr[i].AT,arr[i].BT,arr[i].CT,arr[i].ST,arr[i].TAT,arr[i].WT);
    }
    return 0;
} 