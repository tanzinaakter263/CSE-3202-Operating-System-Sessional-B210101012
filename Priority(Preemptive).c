#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], pr[n], rt[n], ct[n], tat[n], wt[n];
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

        rt[i] = bt[i]; // remaining time
    }

    printf("\nGantt Chart:\n|");


    while(completed < n) {
        int idx = -1;
        int highest = 999;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {

                if(pr[i] < highest ||
                  (pr[i] == highest && (idx == -1 || at[i] < at[idx]))) {
                    highest = pr[i];
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

            rt[idx]--;   // execute 1 unit
            time++;

            if(rt[idx] == 0) {
                completed++;
                ct[idx] = time;
            }
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


   /* int maxCT = ct[0], minAT = at[0];

    for(i = 1; i < n; i++) {
        if(ct[i] > maxCT)
            maxCT = ct[i];
        if(at[i] < minAT)
            minAT = at[i];
    }

    float throughput;
    if(maxCT - minAT != 0)
        throughput = (float)n / (maxCT - minAT);
    else
        throughput = 0;

    printf("\nThroughput = %.2f processes/unit time\n", throughput);*/

    return 0;
}

