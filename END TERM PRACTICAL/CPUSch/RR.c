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

int main() {
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
    quickSort(arr,0,n-1);
    int tq;
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    Queue *q = createQueue(10*n);

    int time = 0;
    int processCompleted = 0;
    int *visited = calloc(n, sizeof(int));

    printf("\n%-15s %-15s %-15s %-15s %-15s %-15s\n",
        "ArrivalTime", "BurstTime", "StartTime", "Completion", "TurnAround", "Waiting");

    while(processCompleted < n) {

        // Add processes that have arrived
        for(int i = 0; i < n; i++) {
            if(!visited[i] && arr[i].AT <= time) {
                Enqueue(q, i);
                visited[i] = 1;
            }
        }

        // If queue empty → CPU idle
        if(isEmpty(q)) {
            time++;
            continue;
        }

        int i = getFront(q);
        Dequeue(q);
        printf("P%d ",i);

        // First time running?
        if(arr[i].RT == arr[i].BT)
            arr[i].ST = time;

        int execTime = (arr[i].RT < tq) ? arr[i].RT : tq;

        time += execTime;
        arr[i].RT -= execTime;

        // Add new arrivals during execution
        for(int j = 0; j < n; j++) {
            if(!visited[j] && arr[j].AT <= time) {
                Enqueue(q, j);
                visited[j] = 1;
            }
        }

        // Process finished
        if(arr[i].RT == 0) {
            arr[i].CT = time;
            arr[i].TAT = arr[i].CT - arr[i].AT;
            arr[i].WT = arr[i].TAT - arr[i].BT;
            arr[i].complete = 1;
            processCompleted++;

            /* printf("%-15d %-15d %-15d %-15d %-15d %-15d\n",
                arr[i].AT, arr[i].BT, arr[i].ST, arr[i].CT, arr[i].TAT, arr[i].WT); */
                
        }
        else {
            // Not finished → requeue
            Enqueue(q, i);
        }
    }

    return 0;
}
