#include <stdio.h>
#include <stdbool.h>

// Function to check if the system is in a safe state
bool isSafe(int n, int m, int available[], int max[][m], int allocation[][m], int need[][m])
{
    int i, j, k, work[m], finish[n];
    // Copy the available array to the work array
    for (i = 0; i < m; i++)
    {
        work[i] = available[i];
    }
    // Initialize all processes as not finished
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }
    // Find a process that can be executed safely
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (finish[j] == 0)
            {
                bool canExecute = true;
                for (k = 0; k < m; k++)
                {
                    if (need[j][k] > work[k])
                    {
                        canExecute = false;
                        break;
                    }
                }
                if (canExecute)
                {
                    // Mark the process as finished and release its resources
                    finish[j] = 1;
                    for (k = 0; k < m; k++)
                    {
                        work[k] += allocation[j][k];
                    }
                }
            }
        }
    }
    // Check if all processes are finished
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    int available[m], max[n][m], allocation[n][m], need[n][m];
    printf("Enter the available resources: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }
    printf("Enter the maximum demand matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    if (isSafe(n, m, available, max, allocation, need))
    {
        printf("The system is in a safe state.\n");
    }
    else
    {
        printf("The system is in an unsafe state.\n");
    }
    return 0;
}

