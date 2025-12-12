#include<stdio.h>
#include<stdlib.h>
int main()
{
    int blockCnt,prcCnt;
    printf("Enter the number of blocks : \n");
    scanf("%d",&blockCnt);
    printf("Enter the number of Processes : \n");
    scanf("%d",&prcCnt);
    int blocks[blockCnt],processes[prcCnt];
    printf("Enter the size of each block :  \n");
    for(int i=0;i<blockCnt;i++)
    {
        scanf("%d",blocks[i]);
    }
    printf("Enter the size of each Process : \n");
    
    for(int i=0;i<prcCnt;i++){
        scanf("%d",processes[i]);
    }

    int allocation[prcCnt];
    for(int i=0;i<prcCnt;i++)
    {
        allocation[i]=-1;
    }
    for(int i=0;i<prcCnt;i++)
    {
        for(int j=0;j<blockCnt;j++)
        {
            if(blocks[j]>=processes[i])
            {
                allocation[i]=j;
                blocks[j]-=processes[i];
                break;
            }
        }
    }

    return 0;
}