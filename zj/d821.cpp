#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
#define inf 10000
struct axis{
    int x,y,len;
};
bool g[52][52];
int ll[52][52];
int dp[52][52];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int sum(int r,int c){
    if(dp[r][c]!=-1){
        return dp[r][c];
    }
    int ans=0;
    for(int m=0;m<4;m++){
        if(ll[r+dx[m]][c+dy[m]]==ll[r][c]-1){
            ans+=sum(r+dx[m],c+dy[m]);
        }
    }
    ans%=100000;
    dp[r][c]=ans;
    return ans;
}
int main(){
    int r,c,i,j,k,m,sx,sy,ex,ey;
    queue<axis> q;
    while(scanf("%d %d",&r,&c)==2){
        for(i=0;i<=r+1;i++){
            for(j=0;j<=c+1;j++){
                if(i==0||j==0||i==r+1||j==c+1){
                    g[i][j]=1;
                }else{
                    scanf("%d",&g[i][j]);
                }
                ll[i][j]=inf;
                dp[i][j]=-1;
            }
        }
        scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
        q.push(axis{sx+1,sy+1,1});
        while(!q.empty()){
            i=q.front().x,j=q.front().y,k=q.front().len;
            q.pop();
            if(!g[i][j]){
                g[i][j]=1;
                ll[i][j]=k;
                for(m=0;m<4;m++){
                    q.push(axis{i+dx[m],j+dy[m],k+1});
                }
            }
        }
        dp[sx+1][sy+1]=1;
        printf("%d\n",sum(ex+1,ey+1));
    }
}
