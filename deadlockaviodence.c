#include <stdio.h>

int main()
{
    int i, j, n, m, k = 0, flag = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    int allocation[n][m], max[n][m], need[n][m], available[m], work[m], finish[n], safe_sequence[n];
    for(i = 0; i < n; i++)
    {
        printf("Enter the allocation matrix for process %d: ", i + 1);
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }
    for(i = 0; i < n; i++)
    {
        printf("Enter the max matrix for process %d: ", i + 1);
        for(j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
        finish[i] = 0;
    }
    printf("Enter the available resources: ");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
        work[i] = available[i];
    }
    while(k < n)
    {
        flag = 0;
        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                flag = 1;
                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                {
                    for(j = 0; j < m; j++)
                    {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = 1;
                    safe_sequence[k] = i + 1;
                    k++;
                }
            }
        }
        if(!flag)
        {
            printf("The system is in deadlock state.\n");
            break;
        }
    }
    if(flag)
    {
        printf("The system is in safe state.\n");
        printf("Safe sequence is: ");
        for(i = 0; i < n; i++)
        {
            printf("%d ", safe_sequence[i]);
        }
    }
    return 0;
}

