#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,m;
    printf("Enter the number of Processes ; \n");
    scanf("%d",&n);
    printf("Enter the instances of each resource ; \n");
    scanf("%d",&m);

    int resource[m];
    printf("Enter the Resources : \n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&resource[i]);
    } 

    printf("Enter the maximum Need : \n");

    int max[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

     printf("Enter Allocated : \n");   
    int allocated[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&allocated[i][j]);
        }
    }
    int need[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-allocated[i][j];
        }
    }

    int finished[n];
    for(int i=0;i<n;i++) finished[i]=0;

    int safeSeq[n];
    int count=0;
    while(count<n)
    {
        int found=0;
        for(int i=0;i<n;i++)
        {
            if(finished[i]) continue;
            int flag=0;
            for(int j=0;j<m;j++)
            {
                if(need[i][j]>resource[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                safeSeq[count++]=i;
                finished[i]=1;
                found=1;
                for(int j=0;j<m;j++)
                {
                    resource[j]+=allocated[i][j];
                     
                }
                 
            }
        }
        if(found==0)
        {
            printf("Safe not Possibel : \n");
            return 0;
        }
    }

    if(count!=n)
    {
        printf("\nProcesses causing deadlock: ");
        int deadlock = 0;
        for(int i = 0; i < n; i++) {
            if(finished[i] == 0) {
                printf("P%d ", i);
                deadlock = 1;
            }
        }
        if(!deadlock)
            printf("None (All processes finished)\n");
        else
            printf("\n");
    }

    // Print Safe Sequence
    printf("\nSystem is in SAFE state.\nSafe Sequence: ");
    for(int i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);

    
    return 0;
}