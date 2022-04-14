#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int prime[80000];
int amt;
int sieve[1000000>>5];
int dp[1000001];
int main(){
    long long i,j,k;
    dp[2]=1;
    prime[amt++]=2;
    for(i=3;i<1000000;i+=2){
        if(((sieve[i>>5]>>(i&31))&1)==0){
            dp[i]=1;
            prime[amt++]=i;
            for(j=i*i;j<1000000;j+=i){
                sieve[j>>5]|=(1<<(j&31));
                dp[j]=~i;//record j's prime factor
            }
        }
    }
    for(i=4;i<=1000000;i++){
        if((i&1)==0){
            dp[i]=dp[i/2]+1;
        }else if(dp[i]<0){
            dp[i]=dp[i/(~dp[i])]+1;
        }
    }
    for(i=3;i<=1000000;i++){
        dp[i]+=dp[i-1];
    }
    int n;
    while(scanf("%d",&n)==1){
        printf("%d\n",dp[n]);
    }
}

