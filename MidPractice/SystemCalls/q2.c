//PRINT CHILD PROCESS ID 
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    pid_t pid=fork();
    if(pid==0)
    {
        printf("In child process , process_id=%d , parent process_id=%d\n",getpid(),getppid());
    }
    else 
    {
        printf("In calling function , process_id=%d",getpid());
    }
    return 0;
}