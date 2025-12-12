#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
 
int main()
{
    int frames,n;
    printf("Enter the number of frames available : \n");
    scanf("%d",&frames);
    printf("Enter the number of requests : \n");
    scanf("%d",&n); 

    int pages[n];
    printf("Enter the requested page numbers : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }
    int frame[frames];
    int pageFaults=0;
    int curr=0;
    for(int i=0;i<frames;i++) frame[i]=-1;
    for(int i=0;i<n;i++)
    {
        int page=pages[i];
        int found=0;
        for(int j=0;j<frames;j++)
        {
            if(frame[j]==page)
            {
                found=1;
                break;
            }
        }
        if(!found)
        {
            frame[curr]=page;
            curr=(curr+1)%frames;
            pageFaults++;
        }
    }

    return 0;
}


#include <stdio.h>

struct PageTable {
    int frame_no;
    int valid;
};
/* 
int main() {
    int frames, n;

    printf("Enter number of frames available : ");
    scanf("%d", &frames);

    printf("Enter number of requests : ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the requested page numbers : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Frame Array
    int frame[frames];

    // Page Table (Assume page numbers are between 0–49)
    struct PageTable PT[50];

    // Initialize frames
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    // Initialize Page Table
    for (int i = 0; i < 50; i++) {
        PT[i].valid = 0;
        PT[i].frame_no = -1;
    }

    int pageFaults = 0;
    int pointer = 0;   // FIFO pointer

    // Process each page request
    for (int i = 0; i < n; i++) {

        int page = pages[i];

        // Check if page is already in memory
        if (PT[page].valid == 0) {
            // Page Fault occurs
            pageFaults++;

            // If a page is in the frame we're replacing,
            // mark it invalid in the page table
            int oldPage = frame[pointer];
            if (oldPage != -1) {
                PT[oldPage].valid = 0;
                PT[oldPage].frame_no = -1;
            }

            // Load new page in frame
            frame[pointer] = page;
            PT[page].valid = 1;
            PT[page].frame_no = pointer;

            // Move FIFO pointer
            pointer = (pointer + 1) % frames;
        }
        // else it is a HIT → do nothing
    }

    printf("Total number of page faults : %d\n", pageFaults);

    return 0;
}
 */