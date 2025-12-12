//FORK -> 0 child , +ve parent
#include<stdio.h>
#include<unistd.h> // FORK 
#include<sys/types.h> // pid

void show()
{
    pid_t pid=fork();
    if(pid<0)
    {
        printf("Fork failed !");
        exit(1);
    }
    printf("Process id = %d",getpid());    
}
void parentWait()
{
    pid_t pid=fork();
    if(pid<0)
    {
        printf("In Child Process ! \n");
    }
    else{
        wait(NULL);
        printf("In Parent Process!\n");
    }
}
void wt()
{
    // after fork , parent and child run concurrently , without wait parent may finish before child 
    pid_t terminatedChild=wait(NULL); //BLOCKS THE PARENT , PARENT WAKES ONLY WHEN CHILD TERMINATES  , PREVENTS ZOMBIE PROCESS 
    pid_t child_pid;
    waitpid(child_pid,NULL,0); // ,  exit status, no spc opt;
}
void slp()
{
    int seconds;
    sleep(seconds);//pauses only the process that calls it , 
}

void waitForFirstChild()
{
    pid_t c1,c2;
    c1=fork();
    if(c1==0)
    {
        sleep(2);
        printf("Child1 finished !\n");
         
    }
    c2=fork();
    if(c2==0)
    {
        sleep(5);
        printf("Child2 Finished!\n");
    }
    waitpid(c1,NULL,0);
     printf("Parent waited for Child 1 only\n");

    // Parent continues; child 2 still running
    sleep(10);
}
int main()
{
    show();
    return 0;
}
