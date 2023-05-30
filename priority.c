#include<stdio.h>

int main() {
    int n, i, j, temp, total_time = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int arrival_time[n], burst_time[n], priority[n], waiting_time[n], turnaround_time[n], completed[n];
    printf("Enter the arrival time, burst time, and priority for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d %d %d", &arrival_time[i], &burst_time[i], &priority[i]);
        waiting_time[i] = 0;
        turnaround_time[i] = 0;
        completed[i] = 0;
        total_time += burst_time[i];
    }
    // Sort the processes by priority using bubble sort
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(priority[j] > priority[j+1]) {
                temp = priority[j];
                priority[j] = priority[j+1];
                priority[j+1] = temp;
                temp = arrival_time[j];
                arrival_time[j] = arrival_time[j+1];
                arrival_time[j+1] = temp;
                temp = burst_time[j];
                burst_time[j] = burst_time[j+1];
                burst_time[j+1] = temp;
            }
        }
    }
    // Execute the processes in a priority fashion
    int current_time = 0, min_priority = 0;
    while(current_time < total_time) {
        // Find the process with the highest priority
        for(i = 0; i < n; i++) {
            if(arrival_time[i] <= current_time && completed[i] == 0) {
                min_priority = i;
                break;
            }
        }
        for(i = min_priority+1;i < n; i++) {
            if(arrival_time[i] <= current_time && completed[i] == 0 && priority[i] < priority[min_priority]) {
                min_priority = i;
            }
        }
        // Execute the process with the highest priority
        current_time += burst_time[min_priority];
        waiting_time[min_priority] = current_time - arrival_time[min_priority] - burst_time[min_priority];
        turnaround_time[min_priority] = current_time - arrival_time[min_priority];
        completed[min_priority] = 1;
    }
    // Calculate the average waiting and turnaround time
    for(i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    // Print the results
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, arrival_time[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time);
    return 0;
}

