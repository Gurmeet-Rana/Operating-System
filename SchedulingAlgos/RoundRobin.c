#include<stdio.h>
#include<stdlib.h>
typedef struct process
{
    int pid,AT,BT,ST,CT,TAT,WT;
}process;

typedef struct queue
{
    int front,rear;
    int size;
    process* arr;
}queue;

queue* createQueue(int n)
{
    queue *q=(queue*)malloc(sizeof(queue));
    q->size=n;
    q->front=-1;
    q->rear=-1;
    q->arr=(process *)malloc(sizeof(process)*(q->size)); 
    return q;
}

void enqueue(queue *q,process val)
{
    if(q->front==q->size-1)
    {
        printf("Overflow!!\n");
        return ;
    }
    q->arr[++q->front]=val;
    if(q->front==1){
        q->rear=1;
    }    

}

process dequeue(queue *q)
{
    if(q->front==-1)
    {
        printf("UnderFlow!!\n");    
        process p;
        return p;   
    }
    else if(q->front==q->rear)
    {
        process val=q->arr[q->front];
        q->front=-1;
        q->rear=-1;
        return val;
    }
    process val=q->arr[q->front];
    q->front++;

    return val;
    
}
process getFront(queue *q)
{
    if(q->front==-1)
    {
        printf("Queue is Empty !\n");
        return ;
    }
}

int main()
{
    int n;
    printf("Enter the number of processes : \n ");
    scanf("%d",&n);
    process *arr;

    arr=(process*)malloc(sizeof(process)*n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the details of the %d th process\n",i+1);
        process p;
        p.pid=i;
        printf("Enter the Arrival Time \n");
        scanf("%d",&p.AT);
        printf("Enter the Burst Time \n");
        scanf("%d",&p.BT);
        arr[i]=p;
    }

    queue *q=createQueue(n);
    int processCompleted=0;
    int time=0;
    while(processCompleted<n)
    {
        
    }

    return 0;
}