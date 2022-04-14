#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define ll long long

struct edge{
    int cur;
    ll w;
    bool operator<(edge& other){
        return w>other.w;
    }
};
ll inf=6000000000;
int n,m;
vector<edge> adj[5001];
edge degree[5001];
ll d[5002][5002];
ll p[5002];
ll mean,son,mom,ans;
stack<edge> bucket[5001];
stack<int> relax;
void dial(int s){
    int i,j,k,cur,flag=0;
    ll w;
    d[s][s]=0;
    for(i=0;i<mom;i++){
        while(!bucket[i].empty()){
            bucket[i].pop();
        }
    }
    while(!relax.empty())relax.pop();
    for(i=0;i<adj[s].size();i++){
        cur=adj[s][i].cur,w=adj[s][i].w;
        if(w<ans)bucket[w*mom/son].push(adj[s][i]);
    }
    for(k=0;k<mom;k++){
        if(bucket[k].empty()){
            continue;
        }
        while(!bucket[k].empty()){
            cur=bucket[k].top().cur;
            w=bucket[k].top().w;
            bucket[k].pop();
            if(d[s][cur]==inf){
                relax.push(cur);
            }
            d[s][cur]=min(d[s][cur],w);
            if(cur==s){
                ans=min(ans,w);
                flag=1;
            }
        }
        if(flag)return;
        while(!relax.empty()){
            i=relax.top();
            relax.pop();
            for(j=0;j<adj[i].size();j++){
                cur=adj[i][j].cur;
                w=adj[i][j].w+d[s][i];
                if(w<ans)bucket[w*mom/son].push(edge{cur,w});
            }
        }
    }
}
void bellman(){
    int i,j,k,cur;
    ll w;
    for(i=1;i<=n;i++)p[i]=inf;
    for(k=1,j=mean;k<=n;k++,j+=mean){//get p(x)
        for(i=1;i<=n;i++){
            if(d[k][i]!=inf)p[i]=min(p[i],d[k][i]-j);
        }
    }
    for(i=1;i<=n;i++){
        for(j=0;j<adj[i].size();j++){
            cur=adj[i][j].cur;
            adj[i][j].w+=p[i]-p[cur];
        }
    }
}
bool karp(){
    int i,j,k,cur;
    ll w,tmpson,tmpmom;
    for(i=0;i<=n+1;i++){
        for(j=0;j<=n;j++){
            d[i][j]=inf;
        }
        p[i]=inf;
    }
    p[0]=d[0][0]=0;
    for(k=0;k<n;k++){
        for(i=0;i<=n;i++){
            for(j=0;j<adj[i].size();j++){
                cur=adj[i][j].cur,w=adj[i][j].w;
                if(d[k][i]!=inf){
                    d[k+1][cur]=min(d[k+1][cur],d[k][i]+w);
                }
                p[cur]=min(p[cur],p[i]+w);
            }
        }
    }
    for(i=1;i<=n;i++){//detect negative cycle
        for(j=0;j<adj[i].size();j++){
            cur=adj[i][j].cur,w=adj[i][j].w;
            if(d[n][i]!=inf){
                d[n+1][cur]=min(d[n+1][cur],d[n][i]+w);
            }
            if(p[cur]>p[i]+w){
                return 0;
            }
        }
    }
    son=inf,mom=1;
    for(i=1;i<=n;i++){//get min mean of the cycle
        if(d[n+1][i]==inf){
            continue;
        }
        tmpson=0-inf,tmpmom=1;
        for(k=1;k<=n;k++){
            if(tmpson*(n+1-k)<(d[n+1][i]-d[k][i])*tmpmom){
                tmpson=d[n+1][i]-d[k][i];
                tmpmom=(n+1-k);
            }
        }
        if(son*tmpmom>tmpson*mom){
            son=tmpson;
            mom=tmpmom;
        }
    }
    mean=son/mom;
    return 1;
}
int main(){
    int t,i,j,k,a,b;
    ll w;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(i=0;i<=n;i++){
            adj[i].clear();
        }
        for(i=1;i<=n;i++){
            adj[0].push_back(edge{i,0});
            degree[i].cur=i;
            degree[i].w=0;
        }
        for(i=0;i<m;i++){
            scanf("%d %d %lld",&a,&b,&w);
            adj[a].push_back(edge{b,w});
            degree[a].w++;
            degree[b].w++;
        }
        if(karp()){
            if(mean==inf){
                printf("INF\n");
            }else{
                bellman();
                for(i=1;i<=n;i++){
                    for(j=1;j<=n;j++){
                        d[i][j]=inf;
                    }
                }
                ans=son;
                sort(degree,degree+n);
                for(i=0;ans&&i<n;i++){
                    dial(degree[i].cur);
                    adj[degree[i].cur].clear();
                }
                printf("%lld\n",ans);
            }
        }else{
            printf("-1\n");
        }
    }
}
