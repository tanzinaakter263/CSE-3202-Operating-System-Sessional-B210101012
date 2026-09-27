#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], pr[n], ct[n], tat[n], wt[n], done[n];
    char pname[n][10];

    // Input
    for(i = 0; i < n; i++) {
        printf("\nProcess %d name: ", i+1);
        scanf("%s", pname[i]);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority (low number = high priority): ");
        scanf("%d", &pr[i]);

        done[i] = 0;
    }

    printf("\nGantt Chart:\n|");


    while(completed < n) {
        int idx = -1;
        int highest = 999;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && done[i] == 0) {

                if(pr[i] < highest) {
                    highest = pr[i];
                    idx = i;
                }

                else if(pr[i] == highest) {
                    if(at[i] < at[idx]) {
                        idx = i;
                    }
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
            time += bt[idx];
            ct[idx] = time;
            done[idx] = 1;
            completed++;
        }
    }

    float totalWT = 0, totalTAT = 0;

    printf("\n\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        totalWT += wt[i];
        totalTAT += tat[i];

        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pname[i], at[i], bt[i], pr[i],
               ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f", totalTAT / n);


    int maxCT = ct[0], minAT = at[0];

    for(i = 1; i < n; i++) {
        if(ct[i] > maxCT)
            maxCT = ct[i];
        if(at[i] < minAT)
            minAT = at[i];
    }

    float throughput = (float)n / (maxCT - minAT);
    printf("\nThroughput = %.2f processes/unit time\n", throughput);

    return 0;
}

