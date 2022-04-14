#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define mod 1000000007
long long f[1000001];
long long g[1000001];
int main(){
    int t,n,i,j;
    f[3]=1;
    g[3]=4;
    g[2]=2;
    g[1]=1;
    for(i=4;i<=1000000;i++){
        f[i]=((f[i-1]<<1)+g[i-3])%mod;
        g[i]=(g[i-1]+g[i-2]+g[i-3])%mod;
        //g[i][0]=g[i-1][0]+g[i-1][1]+g[i-1][2]=g[i-1][0]+g[i-2][0]+g[i-3][0]
        //g[i][1]=g[i-1][0]
        //g[i][2]=g[i-1][1]
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d\n",f[n]);
    }
}
