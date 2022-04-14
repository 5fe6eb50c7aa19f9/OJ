#include <iostream>
#include <cstdio>
using namespace std;

long long fac[14]={1};
long long c[14][14];
long long dp[14][14];//f(i,j): see i numbers, using j numbers
long long ans;
int main(){
    int t,i,j,k,N,P,R;
    for(i=0;i<14;i++)c[i][0]=1;
    for(i=1;i<14;i++){
        fac[i]=fac[i-1]*i;
        for(j=1;j<=i;j++){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
    dp[0][0]=1;
    for(i=1;i<14;i++){
        for(j=i;j<14;j++){
            for(k=0;k<j;k++){
                dp[i][j]+=dp[i-1][j-1-k]*c[j-1][k]*fac[k];
            }
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&N,&P,&R);
        if(N==0){
            if(P==0&&R==0){
                printf("1\n");
            }else{
                printf("0\n");
            }
            continue;
        }
        ans=0;
        for(i=0,j=N-1;i<N;i++,j--){
            if(P-1>=0&&P-1<14&&R-1>=0&&R-1<14)ans+=c[N-1][i]*dp[P-1][i]*dp[R-1][j];
        }
        printf("%lld\n",ans);
    }
}
