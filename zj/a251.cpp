#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int i,n,t;
    int dp[20];
    while(scanf("%d",&t)==1){
        while(t--){
            scanf("%d",&n);
            for(i=0;i<4;i++)scanf("%d",dp+i);
            for(i=4;i<n;i++){
                dp[i]=dp[i-1]+dp[i-4];
            }
            sort(dp,dp+n);
            printf("%d\n",dp[n/2]);
        }
    }
}

