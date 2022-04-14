#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct node{
    int c,d;
    bool operator()(node& a,node& b){
        return a.d>b.d;
    }
};
int res[101][101];
int adj[101][101];
priority_queue<node,vector<node>,node> pq;
int main(){
    int t=0,c,s,q,i,j,c1,c2,d;
    while(scanf("%d %d %d",&c,&s,&q)&&!(c==0&&s==0&&q==0)){
        if(t>0)printf("\n");
        t++;
        for(i=1;i<=c;i++){
            memset(res[i],-1,sizeof(res[i]));
            memset(adj[i],-1,sizeof(adj[i]));
        }
        for(i=0;i<s;i++){
            scanf("%d %d %d",&c1,&c2,&d);
            adj[c1][c2]=d;
            adj[c2][c1]=d;
        }
        for(i=1;i<=c;i++){
            pq.push(node{i,0});
            while(!pq.empty()){
                c2=pq.top().c,d=pq.top().d;
                pq.pop();
                if(res[i][c2]==-1){
                    res[i][c2]=d;
                    for(j=1;j<=c;j++){
                        if(adj[c2][j]!=-1){
                            pq.push(node{j,max(adj[c2][j],d)});
                        }
                    }
                }
            }
        }
        printf("Case #%d\n",t);
        while(q--){
            scanf("%d %d",&c1,&c2);
            if(res[c1][c2]!=-1){
                printf("%d\n",res[c1][c2]);
            }else{
                printf("no path\n");
            }
        }
    }
}
