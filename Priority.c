#include<stdio.h>
int main(){
    int n,i,time=0,completed=0;
    printf("Enter no of process:");
    scanf("%d",&n);
    int at[n],bt[n],ct[n],tat[n],wt[n],done[n],pr[n];
    char pname[n][10];
    for(i=0;i<n;i++){
    printf("\nProcess name:");
    scanf("%s",pname[i]);
    printf("\nArrival Time:");
    scanf("%d",&at[i]);
    printf("\nBurst Time:");
    scanf("%d",&bt[i]);
    printf("\nPriority(Low value=higest priority:");
    scanf("%d",&pr[i]);
    done[i]=0;
    }
    printf("\nGantt Chart\n");
    while(completed<n){
       int idx=-1,highest=999;
        for(i=0;i<n;i++){
            if(at[i]<=time&&done[i]==0){
                if(pr[i]<highest){
                    highest=pr[i];
                    idx=i;
                }
                else if(pr[i]==highest){
                    if(at[i]<at[idx]){
                        idx=i;
                    }
                }
            }
        }
        if(idx==-1){
            printf("Idle |");
            time++;
        }
        else{
            printf("%s |",pname[idx]);
            time+=bt[idx];
            ct[idx]=time;
            done[idx]=1;
            completed++;
        }

    }
    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n:");
    float totalTAT=0,totalWT=0;
    for(i=0;i<n;i++){
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];
    totalTAT+=tat[i];
    totalWT+=wt[i];
    printf("%s\t%d\t%d\t%d\t%d\t%d",pname[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    return 0;



}
