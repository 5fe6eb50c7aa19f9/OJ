#include <cstdio>
#include <iostream>
#include <list>
#include <stack>
using namespace std;

list<int> adj[500000];
list<int>::iterator it;
bool visit[500000];
int cnt[500000];
list<int> bucket[500000];
int main(){
    int t,n,m,i,j,k,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        while(m--){
            scanf("%d %d",&i,&j);
            adj[i].push_front(j);
            adj[j].push_front(i);
        }
        for(i=0,ans=0;i<n;i++){
            visit[i]=1;
            bucket[adj[i].size()].push_front(i);
            cnt[i]=adj[i].size();
            for(it=adj[i].begin(),k=0;it!=adj[i].end();it++){
                if(!visit[*it])k++;
            }
            ans=max(ans,k);
        }
        printf("%d ",ans);
        for(k=0,ans=0;k<n;k++){
            while(!bucket[k].empty()){
                i=bucket[k].front();
                bucket[k].pop_front();
                if(visit[i]){
                    visit[i]=0;
                    ans=k;
                    for(it=adj[i].begin();it!=adj[i].end();it++){
                        if(visit[*it]){
                            cnt[*it]=max(cnt[*it]-1,k);
                            bucket[cnt[*it]].push_front(*it);
                        }
                    }
                    adj[i].clear();
                }
            }
        }
        printf("%d\n",ans);
    }
}
