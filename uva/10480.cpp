#include <cstdio>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;
struct edge{
    int last,next,w;
};
int cap[1005][1005];
int flow[1005][1005];
list<edge> adj[1005];
queue<edge> q;
int p[1005];
int main(){
    int n,m,i,j,k,s=1,t=2,augflow;
    while(scanf("%d %d",&n,&m)==2&&!(n==0&&m==0)){
        while(m--){
            scanf("%d %d %d",&i,&j,&k);
            cap[i][j]+=k;
            cap[j][i]+=k;
            adj[i].push_back(edge{i,j,k});
            adj[j].push_back(edge{j,i,0});
        }
        while(1){
            q.push(edge{s,s,0});
            for(i=1;i<=n;i++)p[i]=0;
            while(q.size()){
                i=q.front().last;
                j=q.front().next;
                q.pop();
                if(p[j])continue;
                p[j]=i;
                for(list<edge>::iterator it=adj[j].begin();it!=adj[j].end();it++){
                    if(cap[j][it->next]-flow[j][it->next]||flow[it->next][j]){
                        q.push(edge{j,it->next,0});
                    }
                }
            }
            if(!p[t])break;
            augflow=0x7fffffff;
            i=t;
            while(i!=s){
                augflow=min(augflow,cap[p[i]][i]-flow[p[i]][i]+flow[i][p[i]]);
                i=p[i];
            }
            i=t;
            while(i!=s){
                flow[p[i]][i]+=augflow;
                if(flow[p[i]][i]>cap[p[i]][i]){
                    flow[i][p[i]]-=flow[p[i]][i]-cap[p[i]][i];
                    flow[p[i]][i]=cap[p[i]][i];
                }
                i=p[i];
            }
        }
        for(i=1;i<=n;i++){
            if(p[i]){
                for(list<edge>::iterator it=adj[i].begin();it!=adj[i].end();it++){
                    if(!p[it->next]){
                        printf("%d %d\n",i,it->next);
                    }
                }
            }
        }
        for(i=1;i<=n;i++){//initialize
            for(j=1;j<=n;j++)cap[i][j]=flow[i][j]=0;
            adj[i].clear();
        }
        printf("\n");
    }
}
