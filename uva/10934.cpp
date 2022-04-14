#include <cstdio>
#include <cstring>
using namespace std;

unsigned long long dp[64][101];//f(try,ball)
int main(){
    int i,j,k,l,r,m,flag;
    unsigned long long n;
    for(i=1;i<=63;i++){
        for(j=1;j<=100;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+1;
        }
    }
    while(scanf("%d %llu",&k,&n)==2&&k!=0){
        l=0,r=64,flag=-1;
        while(l<r){
            m=(l+r)>>1;
            if(dp[m][k]<n){
                l=m+1;
            }else{
                flag=m;
                r=m;
            }
        }
        if(flag==-1){
            printf("More than 63 trials needed.\n");
        }else{
            printf("%d\n",flag);
        }
    }
}
