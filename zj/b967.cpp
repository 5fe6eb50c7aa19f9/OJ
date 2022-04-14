#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> adj[100000];
int deep[100000][2];
int n;
void dfs(int now){
    if(adj[now].size()==0){
        deep[now][0]=deep[now][1]=0;
        return;
    }
    for(int i=0;i<adj[now].size();i++){
        if(deep[adj[now][i]][0]==-1){
            dfs(adj[now][i]);
        }
        deep[now][1]=max(deep[now][1],deep[adj[now][i]][0]+1);
        if(deep[now][1]>deep[now][0])swap(deep[now][1],deep[now][0]);
    }
    if(deep[now][1]==-1)deep[now][1]=0;
}
int main(){
    int i,j,a,b,ans;
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++){
            adj[i].clear();
            deep[i][0]=deep[i][1]=-1;
        }
        for(i=0;i<n-1;i++){
            scanf("%d %d",&a,&b);
            adj[a].push_back(b);
        }
        for(i=0;i<n;i++){
            if(deep[i][0]==-1){
                dfs(i);
            }
        }
        ans=0;
        for(i=0;i<n;i++){
            ans=max(ans,deep[i][0]+deep[i][1]+1);
        }
        printf("%d\n",ans-1);
    }
}
