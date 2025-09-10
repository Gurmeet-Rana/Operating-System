/* Write a program to create child process. Make sure that parent process waits unAl child has 
not  completed  its  execuAon.  (use  wait(),  exit())  What  will  happen  if  parent  process  dies 
before child process? Illustrate it by creaAng one more child of parent process. */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    pid_t pid=fork();
    if(pid<0)
    {
        printf("Fork failed!!\n");
        return 0;
    }
    if(pid==0)
    {
        printf("In child process \n");
        exit(0);
    }
    else{
        // child will become orphan , and who will erase its entry ? 
        wait();
        printf("In parent process !\n");
    }
    return 0;
}