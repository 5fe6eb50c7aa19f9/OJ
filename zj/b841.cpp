/**
similar to a228
O(w*h*2^w)
**/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int dp[2][1<<7];
int g[6][6];
int main(){
    int h,w,i,j,k,state,flag,tmp;
    while(scanf("%d %d",&h,&w)==2){
        state=1<<(w+1);
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                scanf("%d",g[i]+j);
            }
        }
        memset(dp[0],-1,sizeof(dp[0]));
        memset(dp[1],-1,sizeof(dp[1]));
        flag=0;
        dp[flag][0]=0;
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                flag=!flag;
                for(k=0;k<state;k++){
                    if(j!=0){
                        if(((k>>j)&3)==0){
                            if(g[i][j]==g[i][j-1]&&dp[!flag][k+(1<<j)]>=0)dp[flag][k]=max(dp[flag][k],dp[!flag][k+(1<<j)]+1);
                            if(g[i][j]==g[i-1][j]&&dp[!flag][k+(2<<j)]>=0)dp[flag][k]=max(dp[flag][k],dp[!flag][k+(2<<j)]+1);
                            dp[flag][k]=max(dp[flag][k],dp[!flag][k]);
                        }else if(((k>>j)&3)==3){
                            dp[flag][k]=-1;
                        }else{
                            tmp=state-1-(3<<j);
                            dp[flag][k]=dp[!flag][k&tmp];
                        }
                    }else{
                        if((k&3)==0){
                            if(g[i][j]==g[i-1][j]&&dp[!flag][(k>>1)+1]>=0)dp[flag][k]=max(dp[flag][k],dp[!flag][(k>>1)+1]+1);
                            dp[flag][k]=max(dp[flag][k],dp[!flag][k>>1]);
                        }else if((k&3)==3){
                            dp[flag][k]=-1;
                        }else{
                            dp[flag][k]=dp[!flag][(k>>2)<<1];
                        }
                    }
                }
            }
        }
        printf("%d\n",dp[flag][0]);
    }
}
/**
exam:
input:
2 2
1 1
1 2
output:
1
**/
