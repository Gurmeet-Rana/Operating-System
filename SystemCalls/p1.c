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