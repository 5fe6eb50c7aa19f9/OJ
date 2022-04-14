#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long dp[31][3];
int main(){
    dp[0][0]=1;
    dp[1][1]=2;
    int i,j,n;
    for(i=2;i<=30;i++){
        dp[i][0]=dp[i-2][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0]*2+dp[i-1][2];
        dp[i][2]=dp[i-1][1];
    }
    while(scanf("%d",&n)==1&&n!=-1){
        printf("%lld\n",dp[n][0]);
    }
}
