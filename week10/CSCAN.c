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
    printf("Total Seek Movement : %d\n",totalSeekMovement);

    return 0;
}