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
int main()
{
    show();
    return 0;
}
