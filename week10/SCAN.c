#include <stdio.h> 
#include <stdlib.h> 
 
int main() { 
    int n, i, j, temp, head = 50, total = 0; 
    printf("Sample I/O for SCAN:\n\nInput:\n"); 
    printf("Enter number of disk requests : "); 
    scanf("%d", &n); 
 
    int req[n + 1]; 
    for (i = 0; i < n; i++) 
        scanf("%d", &req[i]); 
 
    req[n] = head;  
    for (i = 0; i <= n; i++) { 
        for (j = i + 1; j <= n; j++) { 
            if (req[i] > req[j]) { 
                temp = req[i]; 
                req[i] = req[j]; 
                req[j] = temp; 
            } 
        } 
    } 
    int pos; 
    for (i = 0; i <= n; i++) { 
        if (req[i] == head) { 
            pos = i; 
            break; 
        } 
    } 
   for (i = pos; i < n; i++) 
        total += abs(req[i + 1] - req[i]); 
   for (i = pos - 1; i >= 0; i--) 
        total += abs(req[i + 1] - req[i]); 
} 
