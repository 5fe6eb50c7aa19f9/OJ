#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long dp[50][3];
int main(){
    long long n,i;
    dp[1][0]=1;
    dp[1][1]=1;
    dp[1][2]=0;
    for(i=2;i<50;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][1];
    }
    while(scanf("%lld",&n)==1&&n){
        printf("%lld\n",(1<<n)-dp[n][0]-dp[n][1]-dp[n][2]);
    }
}
