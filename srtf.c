#include <stdio.h>

struct Process {
    int processID;
    int burstTime;
    int remainingTime;
};

void srtf(struct Process processes[], int numProcesses) {
    int currentTime = 0;
    int completedProcesses = 0;
    int shortestRemainingTimeIndex;

    while (completedProcesses != numProcesses) {
        int shortestRemainingTime = INT_MAX;
        shortestRemainingTimeIndex = -1;

        for (int i = 0; i < numProcesses; i++) {
            if (processes[i].burstTime > 0 && processes[i].burstTime < shortestRemainingTime) {
                shortestRemainingTime = processes[i].burstTime;
                shortestRemainingTimeIndex = i;
            }
        }

        if (shortestRemainingTimeIndex == -1) {
            currentTime++;
            continue;
        }

        processes[shortestRemainingTimeIndex].burstTime--;
        currentTime++;

        if (processes[shortestRemainingTimeIndex].burstTime == 0) {
            completedProcesses++;
            printf("Process %d completed at time %d\n", processes[shortestRemainingTimeIndex].processID, currentTime);
        }
    }
}

int main() {
    int numProcesses;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    struct Process processes[numProcesses];
    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].processID = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }

    printf("\nSRTF Scheduling:\n");
    srtf(processes, numProcesses);

    return 0;
}

