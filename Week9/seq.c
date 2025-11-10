#include<stdio.h>
#include<stdbool.h>
typedef struct file 
{
    char name;
    int start_block;
    int no_of_blocks;
}file;
int main()
{
    bool block[1000]={true};
    int n;
    printf("Enter the number of files : \n");
    scanf("%d",&n);
    file files[n];
    for(int i=0;i<n;i++)
    {
        getchar();

    }
}

