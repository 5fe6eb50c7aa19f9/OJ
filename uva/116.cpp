#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long dp[10][100];
int route[10][100][100];
int main(){
    int r,c,i,j,k,tmp;
    long long ans;
    for(i=0;i<10;i++)route[i][0][0]=i;
    while(scanf("%d %d",&r,&c)==2){
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                scanf("%lld",dp[i]+j);
            }
        }
        for(j=1;j<c;j++){
            for(i=0;i<r;i++){
                k=(i-1+r)%r;
                if(dp[k][j-1]>dp[i][j-1]){
                    k=i;
                }else if(dp[k][j-1]==dp[i][j-1]){
                    for(tmp=0;tmp<j;tmp++){
                        if(route[k][j-1][tmp]<route[i][j-1][tmp]){
                            break;
                        }else if(route[k][j-1][tmp]>route[i][j-1][tmp]){
                            k=i;
                            break;
                        }
                    }
                }
                if(dp[k][j-1]>dp[(i+1)%r][j-1]){
                    k=(i+1)%r;
                }else if(dp[k][j-1]==dp[(i+1)%r][j-1]){
                    for(tmp=0;tmp<j;tmp++){
                        if(route[k][j-1][tmp]<route[(i+1)%r][j-1][tmp]){
                            break;
                        }else if(route[k][j-1][tmp]>route[(i+1)%r][j-1][tmp]){
                            k=(i+1)%r;
                            break;
                        }
                    }
                }
                dp[i][j]+=dp[k][j-1];
                for(tmp=0;tmp<j;tmp++)route[i][j][tmp]=route[k][j-1][tmp];
                route[i][j][j]=i;
            }
        }
        for(i=1,k=0,ans=dp[0][c-1];i<r;i++){
            if(dp[k][c-1]>dp[i][c-1]){
                k=i;
                ans=dp[i][c-1];
            }
        }
        for(i=0;i<r;i++){
            if(dp[i][c-1]==ans){
                for(tmp=0;tmp<c;tmp++){
                    if(route[k][c-1][tmp]<route[i][c-1][tmp]){
                        break;
                    }else if(route[k][c-1][tmp]>route[i][c-1][tmp]){
                        k=i;
                        break;
                    }
                }
            }
        }
        for(i=0;i<c;i++){
            if(i)printf(" ");
            printf("%d",route[k][c-1][i]+1);
        }
        printf("\n%lld\n",ans);
    }
}
