#include <cstdio>
using namespace std;

int data[10000][8];
unsigned long long dp[4][8];
int main(){
    int n,i,j,k,a,b,c;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&j,&a,&b,&c);
        k=a*4+b*2+c;
        data[j-1][k]++;
    }
    dp[0][0]=1;
    while(n--){
        for(i=3;i>=1;i--){
            for(j=0;j<8;j++){
                for(k=0;k<8;k++){
                    dp[i][j|k]+=dp[i-1][j]*data[n][k];
                }
            }
        }
    }
    printf("%llu",dp[3][7]);
}
