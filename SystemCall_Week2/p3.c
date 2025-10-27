/* 
Write a program to read a file and store your details in that file. Your program should also 
create one more file and store your friends details in that file. Once both files are created, 
print lines which are matching in both files. 
*/

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 int main()
 {
    FILE *ptr1,*ptr2;
    char line1[256],line2[256];
    ptr1=fopen("mydetails.txt","a");
    if(!ptr1)
    {
        perror("Error Operning mydetails.txt");
        exti(1);
    }
    printf("Enter your details : \n");
    while(1)
    {
        fgets(line1,256,stdin);
        if(strncmp(line1,"END",3)==0)
        {
            break;
        }
        fputs(line1,ptr1);
    }
    fclose(ptr1);
    ptr2=fopen("friend_details.txt","a");
    if(!ptr2)
    {
        perror("Error opening friend_details.txt");
        exit(1);
    }
    printf("Enter your friend's details (Type END in a new line to stop):\n");
    while(1)
    {
        fgets(strncmp(line1,"END",3)==0) break;
        fputs(line1,ptr2);
    }
 }