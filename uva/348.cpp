#include <cstdio>
#include <algorithm>
using namespace std;

const int inf=1e8;
int dp[100][100];
int from[100][100];
int r[100];
int c[100];
int sol(int a,int b){//[a,b)
    if(a>=b)return 0;
    if(dp[a][b]!=inf)return dp[a][b];
    for(int i=a,tmp;i<b;i++){
        tmp=sol(a,i)+sol(i+1,b)+r[a]*c[i]*c[b];
        if(dp[a][b]>=tmp){
            dp[a][b]=tmp;
            from[a][b]=i;
        }
    }
    return dp[a][b];
}
void disp(int a,int b){
    if(a+1==b){
        printf("(A%d x A%d)",a+1,b+1);
        return;
    }
    if(from[a][b]==a){
        printf("(A%d x ",a+1);
        disp(a+1,b);
        printf(")");
    }else if(from[a][b]==b-1){
        printf("(");
        disp(a,b-1);
        printf(" x A%d)",b+1);
    }else{
        printf("(");
        disp(a,from[a][b]);
        printf(" x ");
        disp(from[a][b]+1,b);
        printf(")");
    }
}
int main(){
    int t=1,n,i,j;
    while(scanf("%d",&n)==1&&n){
        for(i=0;i<n;i++){
            scanf("%d %d",r+i,c+i);
        }
        for(i=0;i<n-1;i++){
            for(j=i+1;j<=n-1;j++)dp[i][j]=inf;
        }
        sol(0,n-1);
        printf("Case %d: ",t++);
        disp(0,n-1);
        printf("\n");
        //printf("%d\n",sol(0,n-1));
    }
}
