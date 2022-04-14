#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int coin[]={1,5,10,25,50};
int dp[7490][5];
int f(int v,int r){
    if(dp[v][r])return dp[v][r];
    if(r==0)return 1;
    int i,j;
    for(i=r;i>=1;i--){
        for(j=coin[i];j<=v;j+=coin[i]){
            dp[v][r]+=f(v-j,i-1);
        }
    }
    return ++dp[v][r];
}
int main(){
    int n,i,j;
    for(i=0;i<5;i++)dp[0][i]=1;
    while(scanf("%d",&n)==1){
        printf("%d\n",f(n,4));
    }
}
