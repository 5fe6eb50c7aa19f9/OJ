#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct node{
    int d,now;
};
struct cmp{
    bool operator()(node& a,node& b){
        return a.d>b.d;
    }
};
int edge[1001][1001];
int n;
int g[1001];
int dp[1001];
priority_queue<node,vector<node>,cmp> pq;
int clc(int now){
    if(dp[now]!=-1)return dp[now];
    int ans=0;
    for(int i=1;i<=n;i++){
        if(edge[now][i]!=-1&&g[now]<g[i]){
            ans+=clc(i);
        }
    }
    dp[now]=ans;
    return ans;
}
int main(){
    int m,i,j,a,b,d;
    while(scanf("%d",&n)&&n&&scanf("%d",&m)){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)edge[i][j]=-1;
            g[i]=-1;
            dp[i]=-1;
        }
        for(i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&d);
            edge[a][b]=d;
            edge[b][a]=d;
        }
        dp[1]=1;
        pq.push(node{0,2});
        while(!pq.empty()){
            if(g[pq.top().now]==-1){
                g[pq.top().now]=pq.top().d;
                for(i=1;i<=n;i++){
                    if(edge[pq.top().now][i]!=-1)pq.push(node{pq.top().d+edge[pq.top().now][i],i});
                }
            }
            pq.pop();
        }
        printf("%d\n",clc(2));
    }
}
