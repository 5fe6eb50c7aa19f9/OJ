#include <cstdio>
#include <iostream>
using namespace std;
#define lim 1000000007
int six='1'+'2'+'3';
string st[2];
int dp[10000];
int ans,flag;
void mov(int k,int tar){//mov w(0~k) to tar
    if(k==0){
        if(st[0][0]!=tar){
            if(++ans>=lim)ans-=lim;
        }
        return;
    }

    if(st[0][k]==tar){
        mov(k-2,tar);
    }else{
        mov(k-2,six-tar-st[0][k]);
        ans=ans+1+dp[k/2-1];
        if(ans>=lim)ans-=lim;
    }
    return;
}
int main(){
    int n,i,j;
    dp[0]=1;
    for(i=1;i<10000;i++){
        dp[i]=1+(dp[i-1]<<1);
        if(dp[i]>=lim)dp[i]-=lim;
    }
    while(scanf("%d",&n)&&n){
        getline(cin,st[0]);//buffer
        ans=flag=0;
        getline(cin,st[0]);
        getline(cin,st[1]);
        for(i=(n-1)<<1;i>=0;i-=2){
            if(!flag&&st[0][i]!=st[1][i]){
                if(i-2>=0)mov(i-2,six-st[0][i]-st[1][i]);
                if(++ans>=lim)ans-=lim;
                flag=1;
                j=six-st[0][i]-st[1][i];
            }else if(flag&&j!=st[1][i]){
                ans=ans+dp[i/2-1]+1;
                if(ans>=lim)ans-=lim;
                j=six-st[1][i]-j;
            }
        }
        printf("%d\n",ans);
    }
}