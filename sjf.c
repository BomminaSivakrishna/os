#include<stdio.h>

int main() {
    int n, i, j, temp;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int arrival_time[n], burst_time[n], waiting_time[n], turnaround_time[n],completion_time[n];
    printf("Enter the arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }
    completion_time[0] = arrival_time[0] + burst_time[0];
    for(i = 1; i < n; i++)
    {
        completion_time[i] = completion_time[i - 1] + burst_time[i];
    }
    // Sort the processes by burst time
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(burst_time[i] > burst_time[j]) {
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
                temp = arrival_time[i];
                arrival_time[i] = arrival_time[j];
                arrival_time[j] = temp;
            }
        }
    }
    // Calculate waiting time and turnaround time
    waiting_time[0] = 0;
    for(i = 1; i < n; i++) {
        waiting_time[i] = 0;
        for(j = 0; j < i; j++) {
            waiting_time[i] += burst_time[j];
        }
        waiting_time[i] -= arrival_time[i];
    }
    for(i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
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

