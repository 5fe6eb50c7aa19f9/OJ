#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

bool data[50001];
vector<int> adj[50001];
void dfs(int i){
    data[i]=1;
    for(int j=0;j<adj[i].size();j++){
        if(!data[adj[i][j]]){
            dfs(adj[i][j]);
        }
    }
}
int main(){
    int t=0,i,j,n,m;
    while(scanf("%d %d",&n,&m)==2&&m+n){
        while(m--){
            scanf("%d %d",&i,&j);
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        memset(data,0,sizeof(data));
        for(i=1,j=0;i<=n;i++){
            if(!data[i]){
                j++;
                dfs(i);
            }
        }
        printf("Case %d: %d\n",++t,j);
        for(i=1;i<=n;i++){
            adj[i].clear();
        }
    }
}
