/* Write  a  program  to  communicate  parent  and  child  process  with  each  other  in  such  a  way  that 
whenever child writes something, parent process can read it. Consider mode of communicaAon 
is through message passing  
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h> 
#include<sys/msg.h>
struct msg_buffer
{
    long msg_type; // this is the message type used when sending / receiving . msg_type is an application-defined +ve integer.  
    char msg_text[100]; // msg_text is the payload.
}message;
int main()
{
    key_t key;
    int msgid;
    key=ftok("progfile",65); // generates a key_t value derived from an existing file here "progfile" and a project id "65"; ftok requires that the file exists and is accessible , otherwise it fails or returns -1 . The key is used by msgget() to identify the msg queue across unrelated processes that also call ftok() . 
    msgid=msgget(key,0666|IPC_CREAT); // returns a message-queue identifier for the given key . 0666 are file-permission bits - read and write for owner/group. IPC_CREAT tells the kernel ; create the queue if it doesn't already exist. 
    message.msg_type=1;
    if(fork()==0)
    {
        //CHILD PROCESS WRITES
        strcpy(message.msg_text,"Message From Child");
        msgsnd(msgid,&message,sizeof(message.msg_text),0); // This sends a message to the queue. , 0 is for flags ; 0 means blocking , default behavior; 
    } 
    else
    {
        //Parent process reads 
        msgrcv(msgid,&message,sizeof(message.msg_text),1,0); // receives the message of type 1 . 
        printf("Parent read : %s\n",message.msg_text);
        //Destroy message queue
        msgctl(msgid,IPC_RMID,NULL); // remove(destroy) the message queue from the kernel(clean-up). IPC_RMID - removes the queue; any subsequent msgget() with the same key would create a fresh queue.
        

    }
    return 0;
}