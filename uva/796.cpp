#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
struct DFS{
    int i,p;
};
struct Bridge{
    int p,c;
};
bool cmp(Bridge& a,Bridge& b){
    if(a.p!=b.p)return a.p<b.p;
    return a.c<b.c;
}
int main(){
    int N,i,j,tmp;
    char skip;
    while(scanf("%d",&N)==1){
        int adj[N+1][N+1];
        int amt[N+1];
        int visit[N+1]={0};
        int t=0;
        int low[N+1]={0};
        Bridge bridge[N+1];
        int num=0;
        for(i=0;i<N;i++){
            scanf("%d",&tmp);
            scanf("%c%c",&skip,&skip);
            scanf("%d",&amt[tmp]);
            scanf("%c",&skip);
            for(j=0;j<amt[tmp];j++){
                scanf("%d",&adj[tmp][j]);
            }
        }
        stack<DFS> dfs;
        for(i=0;i<N;i++){
            if(!visit[i]){
                dfs.push(DFS{i,i});
                do{
                    if(!visit[dfs.top().i])visit[dfs.top().i]=low[dfs.top().i]=++t;
                    if(amt[dfs.top().i]>0){
                        while(amt[dfs.top().i]>0){
                            if(!visit[adj[dfs.top().i][--amt[dfs.top().i]]]){
                                dfs.push(DFS{adj[dfs.top().i][amt[dfs.top().i]],dfs.top().i});
                                break;
                            }else if(adj[dfs.top().i][amt[dfs.top().i]]!=dfs.top().p){
                                low[dfs.top().i]=min(low[dfs.top().i],visit[ adj[dfs.top().i][amt[dfs.top().i]] ]);
                            }
                        }
                    }else{
                        int child=dfs.top().i;
                        dfs.pop();
                        if(!dfs.empty()){
                            low[dfs.top().i]=min(low[dfs.top().i],low[child]);
                            if(low[child]>visit[dfs.top().i]){
                                bridge[num++]={min(dfs.top().i,child),max(dfs.top().i,child)};
                            }
                        }
                    }
                }while(!dfs.empty());
            }
        }
        sort(bridge,bridge+num,cmp);
        printf("%d critical links\n",num);
        for(i=0;i<num;i++){
            printf("%d - %d\n",bridge[i].p,bridge[i].c);
        }
        printf("\n");
    }
}
