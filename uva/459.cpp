#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> adj[128];
bool g[128];
void dfs(int i){
    g[i]=1;
    for(vector<int>::iterator it=adj[i].begin();it!=adj[i].end();it++){
        if(!g[*it]){
            dfs(*it);
        }
    }
}
int main(){
    int t,T,n,i,ans;
    string tmp;
    scanf("%d",&T);
    getline(cin,tmp);
    getline(cin,tmp);
    for(t=1;t<=T;t++){
        if(t>1)printf("\n");
        getline(cin,tmp);
        n=tmp[0];
        for(i='A';i<=n;i++){
            g[i]=0;
            adj[i].clear();
        }
        while(getline(cin,tmp)){
            if(tmp=="")break;
            adj[tmp[0]].push_back(tmp[1]);
            adj[tmp[1]].push_back(tmp[0]);
        }
        for(i='A',ans=0;i<=n;i++){
            if(!g[i]){
                dfs(i);
                ans++;
            }
        }
        printf("%d\n",ans);
    }
}
