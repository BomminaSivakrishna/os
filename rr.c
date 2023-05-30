#include<stdio.h>
int main() {
    int n, i, j, quantum, remaining;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int arrival_time[n], burst_time[n], waiting_time[n], turnaround_time[n], remaining_burst_time[n],completion_time[n];
    printf("Enter the arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        remaining_burst_time[i] = burst_time[i];
    }
    completion_time[0] = arrival_time[0] + burst_time[0];
    for(i = 1; i < n; i++)
    {
        completion_time[i] = completion_time[i - 1] + burst_time[i];
    }
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    // Execute the processes in a round robin fashion
    int time = 0;
    remaining = n;
    while(remaining > 0) {
        for(i = 0; i < n; i++) {
            if(arrival_time[i] <= time) {
                if(remaining_burst_time[i] > quantum) {
                    time += quantum;
                    remaining_burst_time[i] -= quantum;
                }
                else {
                    time += remaining_burst_time[i];
                    waiting_time[i] = time - burst_time[i] - arrival_time[i];
                    remaining_burst_time[i] = 0;
                    remaining--;
                }
            }
        }
    }
    // Calculate turnaround time
    for(i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    // Print the results
    printf("\nProcess\tArrival Time\tBurst Time\tCompletionTime\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, arrival_time[i], burst_time[i],completion_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time);
    return 0;
}

