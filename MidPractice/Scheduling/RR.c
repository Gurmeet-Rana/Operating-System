#include<stdio.h>
#include<stdlib.h>

typedef struct Process
{
    int AT,BT,CT,ST,TAT,WT,complete,RT;
}Process;

typedef struct Queue 
{
    int front,rear,size;
    int* arr; // STORE THE INDICES OF THE PROCESSES 
}Queue;

Queue *createQueue(int size)
{
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->size=size;
    q->arr=(int*)malloc(sizeof(int)*size);
    q->front=q->rear=-1;
    return q;
}

void Enqueue(Queue*q,int p)
{
    if(q->rear==-1)
    {
        q->arr[++q->rear]=p;
        ++q->front;
        return ;
    }
    else if(q->rear==q->size-1)
    {
        printf("Overflow!!");
        return ;
    }
    q->arr[++q->rear]=p;
}

void Dequeue(Queue*q)
{
    if(q->front>q->rear)
    {
        printf("Overflow");
        return ;
    }
    if(q->front==q->rear)
    {
        q->front=q->rear=-1;
        return ;
    }
    q->front++;
}
int getFront(Queue *q)
{
    return q->arr[q->front];
}

int isEmpty(Queue *q)
{
    return q->front==-1;
}

void main()
{
    int n;
    printf("Enter the number of Processes : \n");
    scanf("%d",&n);
    Process* arr=(Process*)malloc(sizeof(Process)*n);

    for(int i=0;i<n;i++)
    {
        Process p;
        printf("Enter the Arrival Time : \n");
        scanf("%d",&p.AT);
        printf("Enter the Burst Time : \n");
        scanf("%d",&p.BT);
        p.RT=p.BT;
        p.complete=0;
        arr[i]=p;
    }

    int tq;
    printf("Enter the Time Quantum : \n");
    scanf("%d",&tq);

    Queue *q=createQueue(10*n);

    int time=0;
    int processCompleted=0;
    int *visited=calloc(n,sizeof(int));

    printf("%-15s %-15s %-15s %-15s %-15s %-15s\n","ArrivalTime","BurstTime","StartingTime","Completion Time","TurnAroundTime","WaitingTime");

    while(processCompleted<n)
    {
        for(int i=0;i<n;i++)
        {
            if(visited[i] || arr[i].complete==1 || arr[i].AT>time) continue;
            Enqueue(q,i);
            visited[i]=1;
        }

        if(isEmpty(q)) 
        {
            time++;
            continue;
        }       
        int i=getFront(q);
        Dequeue(q);
        if(arr[i].RT==arr[i].BT)
        {
            arr[i].ST=time;
        }
        int execTime=(arr[i].RT<tq)?arr[i].RT:tq;
        time+=execTime;
        arr[i].RT-=execTime;

        //ADD PROCESSES THAT ARRIVED DURING THIS TIME QUANTUM 
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && arr[j].AT<=time)
            {
                Enqueue(q,j);
                visited[j]=1;
            }
        }

        if(arr[i].RT==0)
        {
            arr[i].CT=time;
            arr[i].TAT=arr[i].CT-arr[i].AT;
            arr[i].WT=arr[i].TAT-arr[i].BT;
            processCompleted++;
            arr[i].complete=1;
            printf("%-15d %-15d %-15d %-15d %-15d %-15d\n",arr[i].AT,arr[i].BT,arr[i].ST,arr[i].CT,arr[i].TAT,arr[i].WT);
        }
        else{
            Enqueue(q,i);
        }
    }

} 