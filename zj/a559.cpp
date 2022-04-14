#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int r,c;
int data[2500][20];
int CmpRes[2500][2500];
int amt[2500];
int dp[2500];
int clc(int i){
    if(dp[i]!=-1)return dp[i];
    dp[i]=0;
    for(int j=0;j<amt[i];j++){
        dp[i]=max(dp[i],clc(CmpRes[i][j]));
    }
    dp[i]++;
    return dp[i];
}
int main(){
    int t,i,j,k,ans;
    while(scanf("%d",&t)==1){
        while(t--){
            scanf("%d %d",&r,&c);
            for(i=0;i<r;i++){
                for(j=0;j<c;j++){
                    scanf("%d",&data[i][j]);
                }
                sort(data[i],data[i]+c);
                amt[i]=0;
                dp[i]=-1;
            }
            for(i=0;i<r;i++){
                for(j=i+1;j<r;j++){
                    for(k=0;k<c;k++){
                        if(data[i][k]==data[j][k]||data[i][k]<data[j][k]!=data[i][0]<data[j][0]){
                            break;
                        }
                        if(k==c-1){
                            if(data[i][0]>data[j][0])CmpRes[i][amt[i]++]=j;
                            else CmpRes[j][amt[j]++]=i;
                        }
                    }
                }
            }
            ans=-1;
            for(i=0;i<r;i++){
                if(dp[i]==-1){
                    clc(i);
                    ans=max(ans,dp[i]);
                }
            }
            printf("%d\n",ans);
        }
    }
}

