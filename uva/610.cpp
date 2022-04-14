#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int n;
bool adj[1001][1001];
int visit[1001];
int t;
int low[1001];

void dfs(int i,int p){
    visit[i]=low[i]=t++;
    for(int j=1;j<=n;j++){
        if(adj[i][j]){
            if(!visit[j]){
                printf("%d %d\n",i,j);
                dfs(j,i);
                if(visit[i]<low[j]){
                    printf("%d %d\n",j,i);//critical bridge
                }
                low[i]=min(low[i],low[j]);
            }else if(j!=p){
                if(visit[i]>visit[j])printf("%d %d\n",i,j);//no matter its "low" is smaller or not,the street need at least a direction
                low[i]=min(low[i],low[j]);
            }
        }
    }
}
int main(){
    int m,i,j,Case=1;
    while(scanf("%d %d",&n,&m)&&!(n==0&&m==0)){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                adj[i][j]=0;
            }
            visit[i]=0;
        }
        t=1;
        while(m-->0){
            scanf("%d %d",&i,&j);
            adj[i][j]=adj[j][i]=1;
        }
        printf("%d\n\n",Case++);
        for(i=1;i<=n;i++){
            if(!visit[i]){
                dfs(i,i);
            }
        }
        printf("#\n");
    }
}
