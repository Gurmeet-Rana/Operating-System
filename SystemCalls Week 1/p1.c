/* Write a program to create a child process using system call fork() */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>  // Fork()
#include<sys/types.h> // pid 
int main()
{
    fork();
    return 0;
}

//FORK IS A SYSTEM CALL USED FOR CREATING A NEW PROCESS , WHICH RUNS CONCURRENTLY WITH THE PROCESS THAT MAKES THE fork() call (Parent process) . THE CHILD PROCESS USES THE SAME PC , SAME , REGISTERS , SAME OPEN FILES WHICH USE IN THE PARENT PROCESS . 
//-> NEGATIVE VALUE - UNSUCCESSFULL
// -> ZERO - CHILD
//-> +VE - returned to parent or caller     