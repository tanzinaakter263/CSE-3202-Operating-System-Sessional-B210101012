#include <stdio.h>

int main(){
    int n,tq,i,time=0,remain;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    char pname[n][10];
    int bt[n],at[n],rt[n],ct[n],tat[n],wt[n];

    for(i=0;i<n;i++){
        printf("\nProcess %d name: ",i+1);
        scanf("%s",pname[i]);
        printf("Arrival Time: "); scanf("%d",&at[i]);
        printf("Burst Time: "); scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    remain=n;

    printf("\nGantt Chart:\n|");

    while(remain>0){
        int executed=0;

        for(i=0;i<n;i++){
            if(rt[i]>0 && at[i]<=time){
                executed=1;

                if(rt[i]>tq){
                    printf(" %s |",pname[i]);
                    time+=tq;
                    rt[i]-=tq;
                }
                else{
                    printf(" %s |",pname[i]);
                    time+=rt[i];
                    ct[i]=time;
                    rt[i]=0;
                    remain--;
                }
            }
        }

        if(!executed){
            printf(" Idle |");
            time++;
        }
    }

    float totalWT=0,totalTAT=0;

    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];

        totalWT+=wt[i];
        totalTAT+=tat[i];

        printf("%s\t%d\t%d\t%d\t%d\t%d\n",
        pname[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAvg WT = %.2f",totalWT/n);
    printf("\nAvg TAT = %.2f",totalTAT/n);



    return 0;
}

