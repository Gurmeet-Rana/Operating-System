/* Write a program to create child process. Make sure that parent process waits until child has 
not  completed  its  execution.  (use  wait(),  exit())  What  will  happen  if  parent  process  dies 
before child process? Illustrate it by creaAng one more child of parent process */

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    pid_t p=fork();
    if(p<0)
    {
        printf("Child not created !");
        exit(1);
    }
    else if(p==0)
    {
        printf("Child process id = %d Parent id = %d\n ",p,getpid());
        exit();
    }
    else
    {
        wait(); // Waits for any child process
        printf("Parent Process id = %d",p);
    }
    return 0;
}