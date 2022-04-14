#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define inf 0x7fffffff
struct edge{
    int x,p,w;
    bool operator()(edge &a,edge &b){
        return a.w>b.w;
    }
};
int n;
vector<edge> adj[1001];
priority_queue<edge,vector<edge>,edge> pq;
int ssp[1001];
int tsp[1001];
int parent[1001];
int path[1001];
int num;
int ret;
void sp(int soursce,int *res){//shortest path
    int i,a,p,w;
    for(i=1;i<=n;i++)res[i]=inf;
    pq.push(edge{soursce,soursce,0});
    while(!pq.empty()){
        a=pq.top().x;
        p=pq.top().p;
        w=pq.top().w;
        pq.pop();
        if(res[a]==inf){
            parent[a]=p;
            res[a]=w;
            for(i=0;i<adj[a].size();i++){
                pq.push(edge{adj[a][i].x,a,w+adj[a][i].w});
            }
        }
    }
}
void replace_path(){
    sp(n,tsp);
    sp(1,ssp);
    ret=0;
    int i,j,a,b,w;
    for(i=n,num=0;i!=1;i=parent[i]){
        path[num++]=i;
    }
    path[num++]=1;
    queue<int> q;
    bool visit[n+1];
    for(i=1;i<=n;i++)visit[i]=0;
    for(i=num-2;i>=0;i--){
        q.push(path[i+1]);
        visit[path[i+1]]=1;
        while(!q.empty()){
            a=q.front();
            q.pop();
            for(j=0;j<adj[a].size();j++){
                b=adj[a][j].x;
                if(visit[b]){
                    continue;
                }else if(a==path[i+1]&&b==path[i]&&adj[a][j].w+ssp[a]+tsp[b]==ssp[n]){
                    w=adj[a][j].w;
                    continue;
                }else if(parent[b]==a&&!(a==path[i+1]&&b==path[i])){
                    q.push(b);
                    visit[b]=1;
                }else{
                    pq.push(edge{b,0,ssp[a]+adj[a][j].w+tsp[b]});
                }
            }
        }
        while(!pq.empty()&&visit[pq.top().x])pq.pop();
        if(pq.empty()){
            ret=max(ret,ssp[n]+w);
        }else{
            ret=max(ret,min(pq.top().w,ssp[n]+w));
        }
    }
}
int main(){
    int i,j,m,a,b,w;
    while(scanf("%d %d",&n,&m)==2){
        for(i=1;i<=n;i++){
            adj[i].clear();
        }
        for(i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&w);
            adj[a].push_back(edge{b,a,w});
            adj[b].push_back(edge{a,b,w});
        }
        replace_path();
        printf("%d\n",ret-ssp[n]);
    }
}
