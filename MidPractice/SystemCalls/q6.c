/* Write a program to show working of execlp() system call by execuAng ls command */
#include<stdio.h>
#include<stdlib.h> 
#include<unistd.h>
 
int main()
{
     printf("Before execlp()\n");
     if(execlp("ls","ls","-1",(char*)NULL)==-1)
     {
        perror("execlp failed");
        exit(EXIT_FAILURE);
     }
     printf("After execlp()\n");
    return 0;
}