#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define MAXN 100000
#define MAXD 17
#define MAXM 500000
//MST
struct edge{
    int a,b,w;
    bool operator<(edge& o){
        return w<o.w;
    }
};
edge e[MAXM];
bool use[MAXM];
int ufs[MAXN];//union-find set
int finding(int i){
    return i==ufs[i]?i:ufs[i]=finding(ufs[i]);
}
//LCA
int maxd;
vector<edge> adj[MAXN];
int p[MAXN][MAXD];
int d[MAXN];
int maxw[MAXN][MAXD];
void dfs(int now,int last){
    int i,j;
    for(i=1;i<maxd;i++){
        p[now][i]=p[p[now][i-1]][i-1];
        maxw[now][i]=max(maxw[now][i-1],maxw[p[now][i-1]][i-1]);
    }
    for(vector<edge>::iterator it=adj[now].begin();it!=adj[now].end();it++){
        if(it->b!=last){
            p[it->b][0]=now;
            d[it->b]=d[now]+1;
            maxw[it->b][0]=it->w;
            dfs(it->b,now);
        }
    }
}
int lca(int a,int b){
    int i,j;
    if(d[a]<d[b])swap(a,b);
    for(i=d[a]-d[b],j=0;i;i>>=1,j++){
        if(i&1)a=p[a][j];
    }
    if(a==b)return a;
    for(i=maxd-1;i>=0;i--){
        if(p[a][i]!=p[b][i]){
            a=p[a][i];
            b=p[b][i];
        }
    }
    return p[a][0];
}
int main(){
    int n,m,i,j,k,l,a,b,w,tmp;
    ll ans1,ans2;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&w);
        e[i].a=a-1,e[i].b=b-1,e[i].w=w;
    }
    sort(e,e+m);
    for(i=0;i<n;i++)ufs[i]=i;
    for(i=0,ans1=0;i<m;i++){
        a=e[i].a,b=e[i].b,w=e[i].w;
        if(finding(a)!=finding(b)){
            ans1+=w;
            use[i]=1;
            ufs[ufs[a]]=ufs[b];
            adj[a].push_back(e[i]);
            e[i].b=a;
            adj[b].push_back(e[i]);
        }
    }
    printf("%lld ",ans1);
    for(i=n,maxd=0;i;i>>=1,maxd++);
    for(i=0;i<maxd;i++)p[0][i]=i;
    d[0]=0;
    for(i=0;i<maxd;i++)maxw[0][i]=0;
    dfs(0,0);
    for(i=0,ans2=0x7fffffffffffffff;i<m;i++){
        if(!use[i]){
            a=e[i].a,b=e[i].b,w=e[i].w;
            j=d[lca(a,b)];
            tmp=0;
            for(k=d[a]-j,l=0;k;k>>=1,l++){
                if(k&1){
                    tmp=max(tmp,maxw[a][l]);
                    a=p[a][l];
                }
            }
            a=b;
            for(k=d[a]-j,l=0;k;k>>=1,l++){
                if(k&1){
                    tmp=max(tmp,maxw[a][l]);
                    a=p[a][l];
                }
            }
            ans2=min(ans2,ans1+w-tmp);
        }
    }
    printf("%lld\n",ans2);
}
