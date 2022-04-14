#include <cstdio>
#include <cstring>

int dp[2][1<<12];
bool flag;
bool floor[11][11];
int main(){
    int t,Case,r,c,i,j,k,state;
    scanf("%d",&t);
    for(Case=1;Case<=t;Case++){
        scanf("%d %d",&r,&c);
        state=1<<(c+1);
        memset(dp[0],0,sizeof(dp[0]));
        memset(dp[1],0,sizeof(dp[1]));
        flag=1;
        dp[flag][0]=1;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                scanf("%d",&floor[i][j]);
            }
        }
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                flag=!flag;
                for(k=0;k<state;k++){
                    if(j>0){
                        if(floor[i][j]&&((k>>(c-j-1))&3)==0){
                            dp[flag][k]=dp[!flag][k+(3<<c-j-1)];
                        }else if(floor[i][j]&&((k>>c-j-1)&3)==3){
                            dp[flag][k]=dp[!flag][k-(3<<c-j-1)];
                        }else if(floor[i][j]){
                            dp[flag][k]=dp[!flag][k^(3<<c-j-1)]+dp[!flag][k];
                        }else if(!floor[i][j]&&((k>>c-j-1)&3)==0){
                            dp[flag][k]=dp[!flag][k];
                        }else{
                            dp[flag][k]=0;
                        }
                    }else{
                        if(floor[i][0]&&((k>>c-1)&3)==0){
                            dp[flag][k]=0;
                        }else if(floor[i][0]&&((k>>c-1)&3)==3){
                            dp[flag][k]=dp[!flag][(k-(3<<c-1))<<1];
                        }else if(floor[i][0]){
                            dp[flag][k]=k>>c?dp[!flag][(k^(3<<c-1))<<1]:dp[!flag][k<<1];
                        }else if(!floor[i][0]&&((k>>c-1)&3)==0){
                            dp[flag][k]=dp[!flag][k<<1];
                        }else{
                            dp[flag][k]=0;
                        }
                    }
                    dp[flag][k]%=1000000007;
                }
            }
        }
        printf("Case %d: %d\n",Case,dp[flag][0]);
    }
}
