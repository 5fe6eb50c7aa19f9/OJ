#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
string tmp;
string data[100];
int N;
bool adj[100][100];
int visit[100];
int t;
int low[100];
int critical[100];
int amt;
int Search(){
    for(int i=0;;i++){
        if(tmp==data[i])return i;
    }
}
void DFS(int now,int p){
    low[now]=visit[now]=++t;
    int son=0;
    for(int i=0;i<N;i++){
        if(adj[now][i]&&i!=p){
            if(visit[i]){
                low[now]=min(low[now],visit[i]);
            }else{
                DFS(i,now);
                if(low[i]>=visit[now])son++;
                low[now]=min(low[now],low[i]);
            }
        }
    }
    if((now==p&&son>1)||(now!=p&&son>0)){
        critical[amt++]=now;
    }
}
bool cmp(int& a,int& b){
    for(int i=0;i<data[a].size()&&i<data[b].size();i++){
        if(data[a][i]!=data[b][i])return data[a][i]<data[b][i];
    }
    return data[a].size()<data[b].size();
}
int main(){
    int n=0,R,i,j,k;
    while(scanf("%d",&N)&&N){
        n++;
        if(n!=1)cout<<endl;
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                adj[i][j]=0;
            }
            visit[i]=0;
        }
        t=0;
        amt=0;
        getline(cin,tmp);
        for(i=0;i<N;i++){
            cin>>data[i];
        }
        scanf("%d",&R);
        getline(cin,tmp);
        for(i=0;i<R;i++){
            cin>>tmp;
            j=Search();
            cin>>tmp;
            k=Search();
            adj[j][k]=adj[k][j]=1;
        }
        for(i=0;i<N;i++){
            if(!visit[i]){
                DFS(i,i);
            }
        }
        sort(critical,critical+amt,cmp);
        printf("City map #%d: %d camera(s) found\n",n,amt);
        for(i=0;i<amt;i++){
            cout<<data[critical[i]]<<endl;
        }
    }
}
