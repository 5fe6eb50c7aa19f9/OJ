#include <cstdio>
#include <algorithm>
#include <iostream>
#include <bitset>
using namespace std;
bool dp[650][650];
int w[33];
int sol(int n){
    int i,j,sum=0,ans=0x7fffffff;
    for(i=1;i<=n;i++)sum+=w[i];
    for(i=sum;i>=0;i--){
        for(j=sum-i;j>=0;j--)dp[i][j]=0;
    }
    dp[0][0]=1;
    while(n){
        for(i=sum;i>=0;i--){
            for(j=sum-i;j>=0;j--){
                if(i>=w[n])dp[i][j]|=dp[i-w[n]][j];
                if(j>=w[n])dp[i][j]|=dp[i][j-w[n]];
            }
        }
        n--;
    }
    for(i=sum;i>=0;i--){
        for(j=sum-i;j>=0;j--){
            if(dp[i][j])ans=min(ans,max(max(i,j),sum-i-j)-min(min(i,j),sum-i-j));
        }
    }
    return ans;
}
int main(){
    int T,t,i,j,n;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",w+i);
        }
        printf("Case %d: %d\n",t,sol(n));
    }
}
