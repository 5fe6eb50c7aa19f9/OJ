#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,i,j;
    int dp[101][101];
    while(scanf("%d",&n)==1){
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                    continue;
                }
                scanf("%d",&dp[i][j]);
                dp[i][j]+=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%d\n",dp[n][n]);
    }
}

