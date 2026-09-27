#include<stdio.h>
void firstFit(int blockSize[],int m,int processSize[],int n){
    int allocation[n];
    for(int i=0;i<n;i++) allocation[i]=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(blockSize[j]>=processSize[i]){
                allocation[i]=j;
                blockSize[j]-=processSize[i];
                break;
            }
        }
    }
    printf("First Fit Allocation\n");
    printf("Process No.\tProcess size\tBlock No.\n");
    for(int i=0;i<n;i++){
        printf("P%d\t\t%d\t\t",i+1,processSize[i]);
        if(allocation[i]!=-1)
            printf("%d\n",allocation[i]+1);
        else
            printf("Not Allocated\n");
    }
}
int main(){
    int m,n;
    printf("Enter no of memory block:");
    scanf("%d",&m);
    printf("\nEnter size of %d memory block:",m);
    int blockSize[m];
    for(int i=0;i<m;i++){
        scanf("%d",&blockSize[i]);
    }

    printf("Enter no of process size:");
    scanf("%d",&n);
    printf("\nEnter size of %d process size",n);
    int processSize[n];
    for(int i=0;i<n;i++){
        scanf("%d",&processSize[i]);
    }
    firstFit(blockSize,m,processSize,n);
    return 0;
}
