#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[20000001],deep;
int sol(long long i){
    if(i<=20000000&&dp[i])return dp[i];
    if(i>20000000){
        int ret=0;
        while(i>20000000){
            if(i&1){
                i=(i*3+1)/2;
                ret+=2;
            }else{
                i>>=1;
                ret++;
            }
        }
        ret+=sol(i);
        return ret;
    }
    if(i&1){
        dp[i]=sol((i*3+1)/2)+2;
    }else{
        dp[i]=sol(i/2)+1;
    }
    return dp[i];
}
struct ST{
    int st[20][1000001];
    int used=0;
    int build(int n){
        int i,j;
        for(i=0;i<n;i++)st[0][i]=dp[i];
        for(j=1;(1<<j)<=n;j++){
            for(i=0;i+(1<<j)<=n;i++){
                st[j][i]=max(st[j-1][i],st[j-1][i+(1<<j-1)]);
            }
        }
    }
    int query(int ql,int qr){
        int k=__lg(qr-ql);
        return max(st[k][ql],st[k][qr-(1<<k)]);
    }
};
ST myst;
int main(){
    int i,j,k;
    dp[1]=1;
    for(i=2;i<=1000000;i++){
        if(!dp[i])dp[i]=sol(i);
    }
    myst.build(1000001);
    while(scanf("%d %d",&i,&j)==2){
        printf("%d %d ",i,j);
        if(i>j)swap(i,j);
        printf("%d\n",myst.query(i,j+1));
    }
}
