#include<stdio.h>
#include<stdlib.h>
 typedef struct Process {
    int AT, BT, CT, ST, TAT, WT, complete, RT;
} Process;

typedef struct Queue {
    int front, rear, size;
    int* arr;
} Queue;

// Create queue
Queue* createQueue(int size) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->size = size;
    q->arr = (int*)malloc(sizeof(int)*size);
    q->front = q->rear = -1;
    return q;
}

// Enqueue
void Enqueue(Queue *q, int p) {
    if(q->rear == q->size - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if(q->front == -1) q->front = 0;
    q->arr[++q->rear] = p;
}

// Dequeue
void Dequeue(Queue *q) {
    if(q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow!\n");
        return;
    }
    if(q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
}

int getFront(Queue *q) {
    return q->arr[q->front];
}

int isEmpty(Queue *q) {
    return (q->front == -1);
}
int main()
{
     int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process* arr = (Process*)malloc(sizeof(Process) * n);

    for(int i = 0; i < n; i++) {
        printf("Enter Arrival Time of P%d: ", i + 1);
        scanf("%d", &arr[i].AT);

        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &arr[i].BT);

        arr[i].RT = arr[i].BT;
        arr[i].complete = 0;
    }
    int tq;
    printf("Enter the Time Quantum : \n");
    scanf("%d",&tq);

    Queue *q=createQueue(10*n);
    int time=0;
    int completed=0;
    int *visited=calloc(n,sizeof(int));
    while(completed<n)
    {
        //ADD Processes that have arrived 
        for(int i=0;i<n;i++)
        {
            if(!visited[i] && arr[i].AT<=time )
            {
                Enqueue(q,i);
                visited[i]=1;
            }
        }
        if(isEmpty(q))
        {
            time++;
            continue;
        }
        int i=getFront(q);
        Dequeue(q);
        // First Time Running ? 
        if(arr[i].RT==arr[i].BT)
        {
            arr[i].ST=time;
        }
        int run=(arr[i].RT<tq)?arr[i].RT:tq;
        arr[i].RT-=run;
        time+=run;
        printf("P%d ",i);

        //ADD NEW ARRIVALS DURING EXECUTION 
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
            arr[i].CT = time;
            arr[i].TAT = arr[i].CT - arr[i].AT;
            arr[i].WT = arr[i].TAT - arr[i].BT;
            arr[i].complete = 1;
           completed++;
        }
        else{
            Enqueue(q,i);
        }
        
    }
}