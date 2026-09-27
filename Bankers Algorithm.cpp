#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter number of processes:\n";
    cin>>n;
    cout<<"\nEnter number of resources:\n";
    cin>>m;
    int alloc[10][10],maxR[10][10],avail[10],need[10][10];
    //Allocation matrix
    cout<<"\nEnter Allocation matrix\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>alloc[i][j];
        }
    }
    //Max matrix
    cout<<"\nEnter Max matrix\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maxR[i][j];
        }
    }
    cout<<"\nEnter avail matrix\n";

        for(int j=0;j<m;j++){
            cin>>avail[j];
        }

        cout<<"\nEnter need matrix\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=maxR[i][j]-alloc[i][j];
            cout<<need[i][j]<<" ";
        }
        cout<<endl;
    }
  int safeSeq[10];
  int count=0;
  int finish[10]={false};
  while(count<n){
    bool found=false;
    for(int i=0;i<n;i++){
        if(!finish[i]){
            bool ok=true;
            for(int j=0;j<m;j++){
                if(need[i][j]>avail[j]){
                    ok =false;
                    break;
                }
            }
            if(ok){
                for(int j=0;j<m;j++){
                    avail[j]+=alloc[i][j];
                }
                safeSeq[count++]=i;
                finish[i]=true;
                found=true;
            }
        }
    }
    if(!found) break;
  }
  if(count==n){
    cout<<"\nSafe Sequence\n";
    for(int i=0;i<n;i++){
        cout<<"p"<<safeSeq[i]<<"";
        if(i<n-1) cout<<" -> ";
    }
    cout<<endl;
  }
  else{
    cout<<"\nUnsafe State\n";
  }
    return 0;
}
