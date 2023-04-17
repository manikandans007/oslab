#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROCESS 100

int main() {
    int blocks[MAX_BLOCKS], processes[MAX_PROCESS];
    int nb, np, i, j;
    int allocation[MAX_PROCESS];
    int fragment[MAX_PROCESS];

    printf("Enter the number of memory blocks: ");
    scanf("%d", &nb);
    printf("Enter the size of each memory block:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &np);
    printf("Enter the size of each process:\n");
    for (i = 0; i < np; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i]);
    }

    for (i = 0; i < np; i++) {
        allocation[i] = -1;
        fragment[i] = -1;
        int max_fragment = -1;
        for (j = 0; j < nb; j++) {
            if (blocks[j] >= processes[i]) {
                if (allocation[i] == -1 || blocks[j] - processes[i] > max_fragment) {
                    allocation[i] = j;
                    max_fragment = blocks[j] - processes[i];
                }
            }
        }
        if (allocation[i] != -1) {
            fragment[i] = max_fragment;
            blocks[allocation[i]] -= processes[i];
        }
    }

    printf("\nProcess\tProcess Size\tBlock\tFragment\n");
    for (i = 0; i < np; i++) {
        printf("%d\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\t%d\n", allocation[i] + 1, fragment[i]);
        } else {
            printf("Not Allocated\n");
        }
    }

    return 0;
}

