#include <iostream>
#include <cstdio>
using namespace std;
int adj[50001];
int visit[50001];
int low[50001];
int dfs(int i){
    visit[i]=0;
    low[i]=i;
    int j=adj[i];
    if(visit[j]==-1){
        visit[i]=dfs(j)+1;
        if(visit[low[j]]==0)low[i]=low[j];
    }else if(visit[j]==0){
        visit[i]=1;
        low[i]=j;
    }else{
        visit[i]=1+visit[low[j]];
    }
    return visit[i];
}
int main(){
    int T,t,n,i,a,b;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            adj[a]=b;
            visit[i+1]=-1;
        }
        a=b=-1;
        for(i=1;i<=n;i++){
            if(visit[i]==-1){
                dfs(i);
                if(b<visit[i]){
                    a=i;
                    b=visit[i];
                }
            }
        }
        printf("Case %d: %d\n",t,a);
    }
}
