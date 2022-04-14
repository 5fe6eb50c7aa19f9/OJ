#include <iostream>
#include <cstdio>
using namespace std;
unsigned long long dp[81][2];
int main(){
    int n,i,j;
    dp[0][1]=1;
    for(i=1;i<81;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    while(scanf("%d",&n)&&n){
        printf("%llu\n",dp[n][0]+dp[n][1]);
    }
}
