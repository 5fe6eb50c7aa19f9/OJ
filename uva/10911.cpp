#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double dp[1<<16];
double data[16][2];
int main(){
    int t=0,n,i,j,k,state,tmp;
    while(scanf("%d",&n)==1&&n){
        n<<=1;
        state=1<<n;
        for(i=0;i<n;i++){
            scanf("%*s %lf %lf",data[i],data[i]+1);
        }
        for(i=0;i<state;i++)dp[i]=1e15;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                dp[(1<<i)+(1<<j)]=sqrt((data[i][0]-data[j][0])*(data[i][0]-data[j][0])+(data[i][1]-data[j][1])*(data[i][1]-data[j][1]));
            }
        }
        dp[0]=0;
        for(i=0;i<state;i++){
            for(j=0;j<n;j++){
                for(k=j+1;k<n;k++){
                    tmp=(1<<j)+(1<<k);
                    if((i&tmp)==tmp){
                        dp[i]=min(dp[i],dp[i^tmp]+dp[tmp]);
                    }
                }
            }
        }
        printf("Case %d: %.2lf\n",++t,dp[state-1]);
    }
}
