#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter the number of Requests : \n");
    scanf("%d",&n);
    int tracks[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tracks[i]);
    }
    int totalSeekMovement=0;
    int prev=0;

    for(int i=1;i<n;i++)
    {
        totalSeekMovement+=abs(tracks[i]-tracks[prev]);
        prev=i;
    }

    printf("Total Seek Movement : %d\n",totalSeekMovement);

    return 0;
}