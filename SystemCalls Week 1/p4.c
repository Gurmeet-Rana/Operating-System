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
        for(int i=0;i<10;i++)
        {
            printf("In child %d \n",i+1);
        }
    }
    else
    {
        printf("In parent !\n");
        while(1);
    }

    //Prevention 
    
}
int main()
{
    
    zombieProcess();
    orphanProcess(); 
    return 0;
}