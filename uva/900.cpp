#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int n,i;
    long long dp[51];
    dp[0]=dp[1]=1;
    for(i=2;i<51;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    while(scanf("%d",&n)==1&&n){
        printf("%lld\n",dp[n]);
    }
}
