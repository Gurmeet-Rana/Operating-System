#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter the number of Requests : \n");
    scanf("%d",&n);
    int req[n];
    printf("Enter the requests : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    int head;
    printf("Enter the head position initially : \n");
    scanf("%d",&head);

    int completed=0;
    int *visited=(int)calloc(n,sizeof(int));
    int move=0;
    while(completed<n)
    {
        int shortest=1e9;
        int temp=-1;
        for(int i=0;i<n;i++)
        {
            if(!visited[i] && req[i]<shortest)
            {
                temp=i;
                shortest=req[i];
            }
        }    
        visited[temp]=1;
        move+=abs(head-req[temp]);
        head=req[temp];
    }

    return 0;
}