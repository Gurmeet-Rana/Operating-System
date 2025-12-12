#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,m;
    printf("Enter number of processes: "); scanf("%d",&n);
    printf("Enter number of resources: "); scanf("%d",&m);

    int avail[m], max[n][m], alloc[n][m], need[n][m];
    printf("Enter Available vector:\n"); for(int i=0;i<m;i++) scanf("%d",&avail[i]);

    printf("Enter Max matrix:\n");
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&max[i][j]);

    printf("Enter Allocation matrix:\n");
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&alloc[i][j]);

    // Calculate Need
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) need[i][j] = max[i][j]-alloc[i][j];

    int pid; 
    printf("Enter Process requesting resources (0-%d): ", n-1); scanf("%d",&pid);

    int req[m];
    printf("Enter Request vector:\n");
    for(int i=0;i<m;i++) scanf("%d",&req[i]);

    // Step 1: Check req <= need
    int flag=0;
    for(int i=0;i<m;i++)
        if(req[i]>need[pid][i]) { flag=1; break; }

    if(flag){ printf("Error: Request exceeds maximum need.\n"); return 0; }

    // Step 2: Check req <= available
    for(int i=0;i<m;i++)
        if(req[i]>avail[i]) { flag=1; break; }

    if(flag){ printf("Resources not available. Request denied.\n"); return 0; }

    // Step 3: Pretend allocation
    for(int i=0;i<m;i++){
        avail[i]-=req[i];
        alloc[pid][i]+=req[i];
        need[pid][i]-=req[i];
    }

    // Step 4: Safety check (same as standard)
    int finished[n], safeSeq[n], count=0;
    for(int i=0;i<n;i++) finished[i]=0;

    while(count<n){
        int found=0;
        for(int i=0;i<n;i++){
            if(!finished[i]){
                int canRun=1;
                for(int j=0;j<m;j++)
                    if(need[i][j]>avail[j]) { canRun=0; break; }
                if(canRun){
                    for(int j=0;j<m;j++) avail[j]+=alloc[i][j];
                    safeSeq[count++]=i;
                    finished[i]=1;
                    found=1;
                }
            }
        }
        if(!found) break;
    }

    if(count==n){
        printf("Request can be granted. Safe sequence: ");
        for(int i=0;i<n;i++) printf("P%d ", safeSeq[i]);
    } else {
        printf("Request cannot be granted. System would be unsafe.\n");
    }

    return 0;
}
