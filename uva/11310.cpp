#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t,i,n;
    long long dp[41][2];//dp[x][0]:lack a peace of cake at x position;
    dp[1][0]=2;
    dp[1][1]=1;
    dp[2][0]=4;
    dp[2][1]=5;
    for(i=3;i<41;i++){
        dp[i][0]=(dp[i-2][1]+dp[i-1][1])<<1;
        dp[i][1]=dp[i-1][1]+dp[i-1][0]+dp[i-2][1]*2;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%lld\n",dp[n][1]);
    }
}

