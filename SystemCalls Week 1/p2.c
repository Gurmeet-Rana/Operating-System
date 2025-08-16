/* Write a program to print process Id's of parent and child process i.e. parent should print its 
own and its child process id while child process should print its own and its parent process 
id. (use getpid(), getppid()) */
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    pid_t pid=fork();
    if(pid==0)
    {
        printf("In a newly created child process id= %d, parent id = %d ",pid,getpid());
        
    }
    else if(pid)
    {
        printf("In the parent process , id = %d",pid);
    }
    else if(pid<0)
    {
        printf("Creating of child process is unsuccessful !");
    }
    return 0;
}