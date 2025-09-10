#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    pid_t pid=fork();
    if(pid<0)
    {
        printf("Fork fail!\n");
        exit(1); 
    }
    printf("Hello World! , process_id(pid)=%d\n",getpid());
    return 0;
}
