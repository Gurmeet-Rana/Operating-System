#include<stdio.h>
#include<stdlib.h>
int Partition(int arr[],int low,int high)
{
    int key=arr[high];
    int i=low-1;
    int j=low;
    while(j<high)
    {
        if(arr[j]<key)
        {
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i],arr[high]);
    return i+1;
}
void quickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pivot=Partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}
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
    int initial_pos=tracks[0];
    quickSort(tracks,0,n-1);
    int totalSeekMovement=0;
    totalSeekMovement+=abs(tracks[n-1]-initial_pos);
    totalSeekMovement+=abs(tracks[0]-initial_pos);
    

    printf("Total Seek Movement : %d\n",totalSeekMovement);

    return 0;
}