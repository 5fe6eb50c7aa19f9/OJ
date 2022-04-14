#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct node{
    int sum,x,y;
};
string g[100];//graph
bool blg[128];//belongings
bool use[128];//can use
int st[100][100];
int n,ans,t;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void dfs(int i){
    if(i==10){
        if(!use[g[0][0]]||!use[g[n-1][n-1]])return;
        queue<node> q;
        t++;
        q.push(node{1,0,0});
        int x,y,nx,ny;
        while(!q.empty()){
            x=q.front().x,y=q.front().y;
            if(st[x][y]!=t){
                if(x==n-1&&y==n-1){
                    ans=min(ans,q.front().sum);
                    return;
                }
                st[x][y]=t;
                for(int i=0;i<4;i++){
                    nx=x+dx[i];
                    ny=y+dy[i];
                    if(nx>=0&&nx<n&&ny>=0&&ny<n&&use[g[nx][ny]]){
                        q.push(node{q.front().sum+1,nx,ny});
                    }
                }
            }
            q.pop();
        }
        return;
    }
    if(blg[i+'a']){
        use[i+'a']=1;
        dfs(i+1);
        use[i+'a']=0;
    }
    if(blg[i+'A']){
        use[i+'A']=1;
        dfs(i+1);
        use[i+'A']=0;
    }
    if(!blg[i+'a']&&!blg[i+'A'])dfs(i+1);
}
int main(){
    int i,j,x,y;
    string buffer;
    node tmp;
    while(scanf("%d",&n)==1){
        getline(cin,buffer);
        memset(blg,0,sizeof(blg));
        memset(use,0,sizeof(use));
        for(i=0;i<n;i++){
            getline(cin,g[i]);
            for(j=0;j<n;j++){
                blg[g[i][j]]=1;
                st[i][j]=0;
            }
        }
        t=0;
        ans=0x7fffffff;
        dfs(0);
        printf("%d\n",ans==0x7fffffff?-1:ans);
    }
}
