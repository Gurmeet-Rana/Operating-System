/* Write  a  program  to  open  a  directory  and  list  its  contents.  
(use opendir(), readdir(), closedir() ) */
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<dirent.h>
int main()
{
    DIR *d;
    struct dirent *dir;
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