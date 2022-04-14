#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//reverse the square by 45', the odd cols only affected by odd cols, the even cols only affected by even cols
long long dp[9][1<<8];//state of 0 ~ n cols
long long ans[9][1<<8];//state of 0~ n+n-1 cols
long long amt1[9];
long long amt2[9];
int main(){
    int i,j,k,n,K,tmp;
    long long ret;
    dp[0][0]=dp[1][0]=dp[1][1]=1;
    for(i=2;i<9;i++){
        for(j=0;j<(1<<i);j++){
            if(j==0){
                dp[i][j]=1;
            }else{
                dp[i][j]=dp[i-2][j];
                for(k=1;k<(1<<i);k<<=1){
                    if(j&k){
                        dp[i][j]+=dp[i-2][j^k];
                    }
                }
            }
        }
    }
    while(scanf("%d %d",&n,&K)==2&&!(n==0&&K==0)){
        for(j=0;j<(1<<n);j++){
            ans[0][j]=dp[n-1][j];
            ans[1][j]=dp[n][j];
        }
        for(i=2,tmp=n-1;tmp>0;i++,tmp--){
            for(j=0;j<(1<<n);j++){
                if(j==0){
                    ans[i][j]=1;
                }else{
                    ans[i][j]=ans[i-2][j];
                    for(k=1;k<(1<<tmp);k<<=1){
                        if(j&k){
                            ans[i][j]+=ans[i-2][j^k];
                        }
                    }
                }
            }
        }
        memset(amt1,0,sizeof(amt1));
        memset(amt2,0,sizeof(amt2));
        for(j=0;j<(1<<n);j++){
            k=__builtin_popcount(j);
            amt1[k]+=ans[i-2][j];
            amt2[k]+=ans[i-1][j];
        }
        for(i=0,ret=0;i<=K;i++){
            j=K-i;
            if(i<=n&&j<=n)ret+=amt1[i]*amt2[j];
        }
        printf("%lld\n",ret);
    }
}
