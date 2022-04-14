#include <cstdio>
#include <iostream>
using namespace std;

#define lim 1000000007
char cur[20001];
char tar[20001];
int dp[10000];
int ans;

int main(){
    int n,i,j,flag,totcur,tmp,six='1'+'2'+'3';
    dp[0]=1;
    for(i=1;i<10000;i++){
        dp[i]=1+(dp[i-1]<<1);
        if(dp[i]>=lim)dp[i]-=lim;
    }
    while(scanf("%d",&n)==1&&n){
        cin.getline(cur,1,'\n');
        cin.getline(cur,n*2,'\n');
        cin.getline(tar,n*2,'\n');
        flag=-1;
        for(i=(n-1)<<1;i>=0;i-=2){
            if(cur[i]!=tar[i]){
                flag=i;
                break;
            }
        }
        ans=0;
        if(flag!=-1){
            totcur=six-cur[flag]-tar[flag];
            ans++;
            for(i=flag-2,tmp=totcur;i>=0;i-=2){
                if(cur[i]==tmp)continue;
                tmp=six-tmp-cur[i];
                ans+=1;
                if(i>0)ans+=dp[i/2-1];
                if(ans>=lim)ans-=lim;
            }
            for(i=flag-2;i>=0;i-=2){
                if(tar[i]!=totcur){
                    totcur=six-totcur-tar[i];
                    ans+=1;
                    if(i>0)ans+=dp[i/2-1];
                    if(ans>=lim)ans-=lim;
                }
            }
        }
        printf("%d\n",ans);
    }
}
