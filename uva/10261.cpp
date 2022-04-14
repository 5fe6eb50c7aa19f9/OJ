#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;

bitset<10001> dp[300];
int l;
int qu[300],sum[300],n;
void trace(int i,int j){
    if(i==0)return;
    if(dp[i-1][j]){
        trace(i-1,j);
        printf("port\n");
    }else{
        trace(i-1,j-qu[i]);
        printf("starboard\n");
    }
}
void sol(){
    int i,j;
    for(i=0;i<n;i++)dp[i].reset();
    dp[0][0]=1;
    for(i=1;i<n;i++){
        sum[i]=qu[i]+sum[i-1];
        if(sum[i]>l*2)break;
        dp[i]=dp[i-1]|(dp[i-1]<<qu[i]);
    }
    for(i=i-1;i>=0;i--){
        for(j=sum[i]/2;j>=0&&sum[i]-j<=l;j--){
            if(dp[i][j]&&sum[i]-j<=l){
                printf("%d\n",i);
                trace(i,j);
                return;
            }
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&l);
        l*=100;
        n=1;
        while(scanf("%d",qu+n)&&qu[n]){
            n++;
        }
        sol();
        if(t)printf("\n");
    }
}
