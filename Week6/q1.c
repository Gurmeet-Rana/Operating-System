/* Write  a  program  to  communicate  parent  and  child  process  with  each  other  in  such  a  way  that 
whenever child writes something, parent process can read it. Consider mode of communicaAon 
is through 
a) pipe  
b) message passing 
c) shared memory 
*/
#include<stdio.h>
#include<unistd.h> // FOR SC like pipe() , fork() , read() and write();
#include<string.h> 

int main()
{
    // Pile is a unidirectional communication channel used between realted processes , it has two ends fd[0] , fd[1]; 
    int fd[2]; // fd[0]-> read end , fd[1]-> write end
    pid_t pid;
    char write_msg[50]="Hello From Child Process : \n"; // Message that will be sent by the child.
    char read_msg[50]; // Buffer where the parent will store the received message.
    if(pipe(fd)==-1) // A system call to create a pipe 
    {
        perror("Pipe Failed!");
        return 0;
    }
    pid=fork(); // creates a new child process ; 
    if(pid<0)
    {
        perror("Fork Failed!");
        return 0;

    }
    if(pid==0) // Child Process
    {
        close(fd[0]); //Close Reading End; The Child will only write , if not closed it can cause issues like deadlocks;

        write(fd[1],write_msg,strlen(write_msg)+1);
        close(fd[1]); // Now close the writing end.
    }
    else
    {
        close(fd[1]); //Close Writing End 
        read(fd[0],read_msg,sizeof(read_msg));
        printf("Parent Read : %s\n",read_msg);
        close(fd[0]);
    }

    return 0;
}