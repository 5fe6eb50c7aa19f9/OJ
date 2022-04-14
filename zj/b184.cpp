#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,i,j,v,m;
    int dp[101];
    while(scanf("%d",&n)==1){
        for(i=0;i<101;i++)dp[i]=0;
        for(i=0;i<n;i++){
            scanf("%d %d",&m,&v);
            for(j=100;j-m>=0;j--){
                dp[j]=max(dp[j],dp[j-m]+v);
            }
        }
        printf("%d\n",dp[100]);
    }
}

