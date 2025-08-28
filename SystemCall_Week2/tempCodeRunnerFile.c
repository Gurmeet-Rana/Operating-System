#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    printf("Before execlp() call\n");
    if(execlp("ls","ls","-1",NULL)==-1)
    {
        perror("execlp failed");
        exit(1);
    }
    printf("After execlp() call\n");
    return 0;
}