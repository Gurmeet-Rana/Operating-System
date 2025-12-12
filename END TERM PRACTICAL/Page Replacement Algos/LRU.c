#include<stdio.h>
#include<stdlib.h>
int main()
{
    int frames,n;
    printf("Enter the number of frames available : \n");
    scanf("%d",&frames);
    printf("Enter the number of requests : \n");
    scanf("%d",&n);
    int pages[n];
    printf("Enter the requested page numbers : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }
    int frame[frames];
    int last_used[frames]; // to track last used time of each frame
    int pageFaults=0;
     
    for(int i=0;i<frames;i++)
    {
        frame[i]=-1;
        last_used[i]=-1;
    }
    int time=0;
    for(int i=0;i<n;i++)
    {
        int page=pages[i];
        int found=0;
        for(int j=0;j<frames;j++)
        {
            if(frame[j]==page)
            {
                found=1;
                last_used[j]=time;
                break;
            }
        }
        if(!found)
        {
            int emptyFrame=-1;
            for(int j=0;j<frames;j++)
            {
                if(frame[j]==-1)
                {
                    emptyFrame=j;
                    break;
                }
            }
            if(emptyFrame==-1)
            {
                frame[emptyFrame]=page;
                last_used[emptyFrame]=time;
            }
            else{
                //FIND LRU PAGE
                int lruIndex=0;
                int minTime=last_used[0];
                for(int j=1;j<frames;j++)
                {
                    if(last_used[j]<minTime)
                    {
                        minTime=last_used[j];
                        lruIndex=j;
                    }
                }
                //Replace the LRU PAGE 
                frame[lruIndex]=page;
                last_used[lruIndex]=time;
            }
            pageFaults++;
        }
    }

    return 0;
}