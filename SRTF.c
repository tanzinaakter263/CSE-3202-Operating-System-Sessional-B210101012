#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], rt[n], ct[n], tat[n], wt[n];
    char pname[n][10];

    // Input
    for(i = 0; i < n; i++) {
        printf("\nProcess %d name: ", i+1);
        scanf("%s", pname[i]);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i]; // Remaining time
    }

    printf("\nGantt Chart:\n|");


    while(completed < n) {
        int idx = -1;
        int min = 999;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(rt[i] < min) {
                    min = rt[i];
                    idx = i;
                }
            }
        }

        // CPU Idle
        if(idx == -1) {
            printf(" Idle |");
            time++;
        }
        else {
            printf(" %s |", pname[idx]);

            rt[idx]--;
            time++;


            if(rt[idx] == 0) {
                completed++;
                ct[idx] = time;
            }
        }
    }

    float totalWT = 0, totalTAT = 0;

    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        totalWT += wt[i];
        totalTAT += tat[i];

        printf("%s\t%d\t%d\t%d\t%d\t%d\n",
               pname[i], at[i], bt[i],
               ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f", totalTAT / n);

    return 0;
}

