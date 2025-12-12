#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void OrphanProcess() 
{
    //After a fork(), if the parent process exits BEFORE the child , then the child is left parentless -> such a child is called an Orphan . 
    pid_t c1=fork();
    if(c1<0)
    {
        printf("FORK FAILED !\n");

    } 
    else if(c1==0)
    {
        sleep(5);
        printf("Child: Orphan Now . Pid = %d\n",getppid());
    }
    else{
        printf("Parent Exiting....\n");
        return 0;
    }

    // SOLUTION : wait(NULL) in parent ;
}
void ZombieProcess()
{
    // A Zombie is a child process that has finished execution , but its parent has not yet collected its exit status using wait() or waitpid()
    pid_t child=fork();
    if(child==0)
    {
        printf("Child Exiting : \n");
        exit(0);
    }
    else{
        printf("Parent Sleeping : \n");
        sleep(10); //Parent does NOT call wait()
        printf("Parent Exiting \n");
    }

    // SOLUTION : Parent call wait(NULL) or wait(pid,NULL,0);

}
int main()
{
    return 0;
}
