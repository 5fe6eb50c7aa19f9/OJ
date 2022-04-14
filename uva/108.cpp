#include <iostream>
#include <cstdio>
using namespace std;

int data[101][101];
int n;
int sol(int clean){
    int i,j,k,ret=0x80000000,sum;
    for(i=clean+1;i<=n;i++){
        for(j=1,sum=0;j<=n;j++){
            sum+=data[i][j]-data[clean][j];
            ret=max(ret,sum);
            if(sum<0)sum=0;
        }
    }
    return ret;
}
int main(){
    int i,j,ans;
    while(scanf("%d",&n)==1){
        ans=0x80000000;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",data[i]+j);
            }
            for(j=1;j<=n;j++)data[i][j]+=data[i-1][j];
        }
        for(i=0;i<n;i++){
            ans=max(ans,sol(i));
        }
        printf("%d\n",ans);
    }
}
