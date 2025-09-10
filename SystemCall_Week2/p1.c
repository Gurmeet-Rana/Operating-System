/* Write  a  program  to  open  a  directory  and  list  its  contents.  
(use opendir(), readdir(), closedir() ) */
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<dirent.h> // directry entry handling library 
int main()
{
    DIR *d; // Represents an open directory stream , it is a ptr to each structure 
    struct dirent *dir; // pointer that represents a single entry in a directory 

    char path[216];
    printf("Enter directory path : ");
    scanf("%255s",path);

    d=opendir(path);

    if(!d)
    {
        printf("Couldn't open directory %s\n",path);
        return 1;
    }
    printf("Contents of %s:\n",path);
    while((dir=readdir(d))!=NULL)
    {
        printf("%s\n",dir->d_name);
    }
    closedir(d);
    return 0;
}