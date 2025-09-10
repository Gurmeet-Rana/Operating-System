#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    /* 
    ORPHAN PROCESS 

    pid_t pid=fork();
    if(pid==0)
    {
        printf("In child process , process_id=%d , parent process_id=%d\n",getpid(),getppid());
        wait();
    }   
    else
    {
        printf("In parent process , process_id=%d\n ",getpid());
        exit();
    } */

    //ZOMBIE PROCESS , CHILD GONE BUT STILL HAVE ENTRY BUT PARENT IS STILL THERE 
    pid_t pid=fork();
    if(pid==0)
    {
        printf("In child process , process_id=%d , parent process_id=%d\n",getpid(),getppid());
        exit(0);
    }
    else
    {
        sleep(1000);
    }
    return  0;
}