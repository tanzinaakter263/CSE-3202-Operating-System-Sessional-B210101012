#include<stdio.h>
int main(){
    int i,n,time=0,completed=0;
    printf("Enter no of process:");
    scanf("%d",&n);
    int at[n],bt[n],ct[n],tat[n],wt[n],rt[n];
    char pname[n][10];
    for(i=0;i<n;i++){
        printf("\nProcess name:");
        scanf("%s",pname[i]);
        printf("\nArrival time:");
        scanf("%d",&at[i]);
        printf("\nBurst time:");
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    printf("\nGantt Chart:");
    while(completed<n){
        int idx=-1,min=999;
        for(i=0;i<n;i++){
            if(at[i]<=time&&rt[i]>0){
                if(rt[i]<min){
                    min=rt[i];
                    idx=i;
                }
            }
        }
        if(idx==-1){
            printf("Idle |");
            time++;
        }
        else{
            printf("%s |",pname[idx]);
            rt[idx]--;
            time++;

            if(rt[idx]==0){
                completed++;
                ct[idx]=time;
            }
        }
    }
    printf("\n\nprocess\tAT\tBT\tCT\tTAT\tWT\n");
    float totalTAT=0,totalWT=0;
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        totalTAT+=tat[i];
        totalWT+=wt[i];
        printf("%s\t%d\t%d\t%d\t%d\t%d\n",pname[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAvg TAT:%.2f",totalTAT/n);
    printf("\nAvg WT:%.2f",totalWT/n);
    return 0;

}
