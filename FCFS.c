 #include<stdio.h>
#include<string.h>
int main(){
    int n,i,j,time=0;
    printf("Enter number of process:");
    scanf("%d",&n);
    int at[n],bt[n],wt[n],tat[n],ct[n];
    char pname[n][10],temp[10];
    for(i=0;i<n;i++){
    printf("\nEnter process name:");
    scanf("%s",pname[i]);
    printf("\nEnter Arrival time:");
    scanf("%d",&at[i]);
    printf("\nEnter Burst time:");
    scanf("%d",&bt[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(at[i]>at[j]){
                int t=at[i];
                at[i]=at[j];
                at[j]=t;
                t=bt[i];
                bt[i]=bt[j];
                bt[j]=t;
                strcpy(temp,pname[i]);
                strcpy(pname[i],pname[j]);
                strcpy(pname[j],temp);
            }
        }
    }

    printf("\nGantt Chart:\n|");
    for(i=0;i<n;i++){
        if(time<at[i]){
            printf("Idle|");
            time=at[i];
        }
        printf("%s |",pname[i]);
        time+=bt[i];
        ct[i]=time;
    }
    float totalTAT=0,totalWT=0;

    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];

    totalTAT+=tat[i];
    totalWT+=wt[i];

    printf("%s\t%d\t%d\t%d\t%d\t%d\n",pname[i],at[i],bt[i],tat[i],ct[i],wt[i]);
    }
    printf("\nAvg TAT:%.2f",totalTAT/n);
    printf("\nAvg WT:%.2f",totalWT/n);
    return 0;


}
