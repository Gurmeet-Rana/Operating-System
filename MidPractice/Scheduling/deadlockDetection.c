#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n;
    printf("Enter the number of processes : \n");
    scanf("%d",&n);
    int max[n][3];
    int allocated[n][3];    
    int available[3],finish[n];
    printf("Enter the available instances of resources A , B and C \n");
    for(int i=0;i<3;i++) scanf("%d",&available[i]);
    
    int need[n][3];
    for(int i=0;i<n;i++)
    {
        printf("Enter Values for A , B and C \n");
        for(int j=0;j<3;j++)
        {
            printf("Enter max : \n");
            scanf("%d",&max[i][j]);
            
            printf("Enter allocated : \n");
            scanf("%d",&allocated[i][j]);

            need[i][j]=max[i][j]-allocated[i][j];
        }
        finish[i]=0;
    }

    int processCompleted=0;
    printf("Safe Sequence is : \n");
    while(processCompleted<n)
    {
        int eligible=-1;
        for(int i=0;i<n;i++)
        {
            if(finish[i]) continue;
            int flag=1;
            for(int j=0;j<3;j++)
            {
                if(available[j]<need[i][j])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                eligible=i;
                break;
            }
        }
        if(eligible==-1)
        {
            printf("Deadlock !\n");
            break;
        }
        processCompleted++;

        
        for(int j=0;j<3;j++)
        {
            available[j]+=allocated[eligible][j];
        }
        finish[eligible]=1;
        
    }
    printf("No Deadlock !!");
    
}
