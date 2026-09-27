#include<stdio.h>
int main(){
    int n,i,time=0,completed=0;
    printf("Enter no of processes:");
    scanf("%d",&n);
    int at[n],bt[n],tat[n],wt[n],ct[n],done[n];
    char pname[n][10];
   for(i=0;i<n;i++){
    printf("\nProcess Name:");
    scanf("%s",pname[i]);
    printf("\nArrival time:");
    scanf("%d",&at[i]);
    printf("\nBurst time:");
    scanf("%d",&bt[i]);
    done[i]=0;
   }

   while(completed<n){
    int Idx=-1,min=999;
    for(i=0;i<n;i++){
        if(at[i]<=time&&done[i]==0){
            if(bt[i]<min){
                min=bt[i];
                Idx=i;
            }

            else if(bt[i]==min){
                if(at[i]<at[Idx]){
                    Idx=i;
                }
            }
        }
    }
    if(Idx==-1){
        printf("Idle |");
        time++;
    }
    else{
        printf("%s |", pname[Idx]);
        time+=bt[Idx];
        ct[Idx]=time;
        done[Idx]=1;
        completed++;
   }
   }

   printf("\n\nProcess\tAT\tBT\tTAT\tWT\tCT\n");
   float totalTAT=0,totalWT=0;
   for(i=0;i<n;i++){
   tat[i]=ct[i]-at[i];
   wt[i]=tat[i]-bt[i];
    totalTAT+=tat[i];
    totalWT+=wt[i];
    printf("%s\t%d\t%d\t%d\t%d\t%d\n",pname[i],at[i],bt[i],ct[i],tat[i],wt[i]);
   }
   printf("\nAVG TAT:%.2f",totalTAT/n);
   printf("\nAVG WT:%.2f",totalWT/n);
}
