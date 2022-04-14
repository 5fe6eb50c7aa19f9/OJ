#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
#define MAXSIZE 100001
vector<int> adj[MAXSIZE];
int index,visit[MAXSIZE],low[MAXSIZE];
stack<int> stk;
bool instk[MAXSIZE];
int comp[MAXSIZE],indegree[MAXSIZE];
void SCC(int i){
    visit[i]=low[i]=index++;
    stk.push(i);
    instk[i]=1;
    for(vector<int>::iterator it=adj[i].begin();it!=adj[i].end();it++){
        if(!visit[*it]){
            SCC(*it);
            low[i]=min(low[i],low[*it]);
        }else if(instk[*it]){
            low[i]=min(low[i],low[*it]);
        }
    }
    if(low[i]==visit[i]){
        int j;
        do{
            j=stk.top();
            stk.pop();
            instk[j]=0;
            comp[j]=i;
            indegree[j]=0;
        }while(j!=i);
    }
}
int main(){
    int t,n,m,i,j,res;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        while(m--){
            scanf("%d %d",&i,&j);
            adj[i].push_back(j);
        }
        for(i=1,index=1;i<=n;i++){
            if(!visit[i])SCC(i);
        }
        for(i=1;i<=n;i++){
            for(vector<int>::iterator it=adj[i].begin();it!=adj[i].end();it++){
                if(comp[i]!=comp[*it]){
                    indegree[comp[*it]]++;
                }
            }
        }
        for(i=1,res=0;i<=n;i++){
            if(i==comp[i]&&!indegree[i])res++;
        }
        printf("%d\n",res);
        for(i=1;i<=n;i++){
            adj[i].clear();
            visit[i]=0;
        }
    }
}
