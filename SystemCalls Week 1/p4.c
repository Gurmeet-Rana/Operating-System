/* Write a program to implement Orphan and Zombie Process.  */

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void zombieProcess()
{
    // Zombie Process : Process which has finished its execution but still remains in the process table because its parent process has not yet read its exit status . 
    pid_t p=fork();
    if(p==0)
    {
        printf("Child process (Zombie Demo) PID : %d\n",getpid());  

        exit(0); //Child exits , becomes zombie until parent calls wait . 

    }
    else
    {
        sleep(10); // Parent sleeps , child becomes zombie  
        wait(NULL); //Parent collets child;s exit status , zombie is cleaned up .
        printf("Parent cleaned up zombie child !\n");
         
    }

    
}
void orphanProcess()
{
    //Orphan process is the process whose parent has terminated while the child is still running 
    pid_t p=fork();
    if(p>0)
    {
        printf("Parent process (Orphan Demo) id = %d\n",getpid());
        exit(0);
    }  
    else if(p==0)
    {
        sleep(5);
        printf("Child process orphan id= %d parent id =%d \n",getpid(),getppid());
        
    }

}
int main()
{
    
    zombieProcess();
    orphanProcess(); 
    return 0;
}