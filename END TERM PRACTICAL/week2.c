/* Write  a  program  to  open  a  directory  and  list  its  contents.  
(use opendir(), readdir(), closedir() )  */

/* Write a program to show working of execlp() system call by execuAng ls command */

/* Write a program to read a file and store your details in that file. Your program should also 
create one more file and store your friends details in that file. Once both files are created, 
print lines which are matching in both files.  */

#include<stdio.h>
#include<dirent.h> //For opendir(), readdir(),closedir()
#include<stdlib.h>

void question1()
{
    DIR *dp; // DIR is a data type used in C to represent a directory system . 

    struct dirent *entry; // structure that represents one entry inside a directory .

    dp=opendir(".");
    printf("Directory Contents:\n");
    while((entry==readdir(dp)))
    {
        printf("%s\n",entry->d_name);
    }
    //Close directory
    closedir(dp);
}

void question2()
{
    printf("Before execlp()\n");
    //execlp(command,arg0,arg1,...,NULL)
    execlp("ls","ls",NULL); // Prints list of files in curr directory 

    //This line executes ONLY if execlp fails 
    printf("Fail");
}

void question3()
{
    #define MAX 100
    FILE *fp1,*fp2;
    char line1[MAX],line2[MAX];
    //CREATE FIRST FILE 
    fp1=open("file1.txt","w");
    printf("Enter number of lines for your details: ");
    int n1;
    scanf("%d", &n1);
    getchar();  // clear newline

    printf("Enter your details (line by line):\n");
    for (int i = 0; i < n1; i++) {
        fgets(line1, MAX, stdin);
        fputs(line1, fp1);
    }
    fclose(fp1);

    //CREATE SECOND FILE 
    fp2=open("file2.txt","w");
    int n2;
    printf("\nEnter number of lines for your friend's details: ");
    scanf("%d", &n2);
    getchar();  // clear newline

    printf("Enter your friend's details (line by line):\n");
    for (int i = 0; i < n2; i++) {
        fgets(line2, MAX, stdin);
        fputs(line2, fp2);
    }
    fclose(fp2);


    //COMPARE FILES 
    fp1 = fopen("file1.txt", "r");
    fp2 = fopen("file2.txt", "r");

    printf("\nMatching Lines:\n");

    // Compare line by line
    while (fgets(line1, MAX, fp1) != NULL) {
        rewind(fp2);     // important: go to beginning of 2nd file each time

        while (fgets(line2, MAX, fp2) != NULL) {
            if (strcmp(line1, line2) == 0) {
                printf("%s", line1);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
}

int main()
{
    
    return 0;
}

