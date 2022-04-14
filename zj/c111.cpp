#include <iostream>
#include <cstdio>
using namespace std;
int adj[100][100];
int amt[100];
int t;
int visit[100];
int low[100];
int ans;
void DFS(int now,int p){
    low[now]=visit[now]=++t;
    int child=0;
    for(int i=0;i<amt[now];i++){
        if(!visit[adj[now][i]]){
            DFS(adj[now][i],now);
            if(visit[now]<=low[adj[now][i]])child++;
            low[now]=min(low[now],low[adj[now][i]]);
        }else if(adj[now][i]!=p){
            low[now]=min(low[now],visit[adj[now][i]]);
        }
    }
    if((now==p&&child>1)||(now!=p&&child>0))ans++;
}
int main(){
    int N,i,j,k;
    string tmp;
    while(scanf("%d",&N)&&N){
        for(i=1;i<=N;i++){
            amt[i]=0;
            visit[i]=0;
        }
        while(scanf("%d",&i)&&i){
            getline(cin,tmp);
            tmp+=" ";
            for(j=0,k=0;j<tmp.size();j++){
                if(tmp[j]>='0'&&tmp[j]<='9'){
                    k=k*10+tmp[j]-'0';
                }else if(tmp[j-1]>='0'&&tmp[j-1]<='9'){
                    adj[i][amt[i]++]=k;
                    adj[k][amt[k]++]=i;
                    k=0;
                }
            }
        }
        t=0;
        ans=0;
        for(i=1;i<=N;i++){
            if(!visit[i]){
                DFS(i,i);
            }
        }
        printf("%d\n",ans);
    }
}
