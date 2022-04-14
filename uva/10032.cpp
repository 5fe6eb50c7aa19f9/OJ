#include <cstdio>
#include <algorithm>
#include <iostream>
#include <bitset>
using namespace std;
#define ll unsigned long long
ll dp[45001];
int w[101];
void sol(int n){
    int i,j,sum=0;
    ll one=1;
    for(i=1;i<=n;i++)sum+=w[i];
    for(i=0;i<=sum;i++)dp[i]=0;
    dp[0]=1;
    for(i=1;i<=n;i++){
        for(j=sum/2;j>=w[i];j--){
            dp[j]|=dp[j-w[i]]<<1;
        }
    }
    for(i=sum/2;i>=0;i--){
        if(dp[i]&(one<<(n/2))){
            break;
        }else if(dp[i]&(one<<(n/2+n%2))){
            break;
        }
    }
    printf("%d %d\n",i,sum-i);
    return;
}
int main(){
    int t,i,j,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",w+i);
        }
        sol(n);
        if(t)printf("\n");
    }
}
