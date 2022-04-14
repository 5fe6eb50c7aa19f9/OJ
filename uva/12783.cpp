#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int adj[1000][1000];//adj list
int amt[1000];//record adj amount
int visit[1000];
int t;
int low[1000];
int bridge[10000][2];
int b;//bridge amount
int* ans[10000];//bridge pointer for sorting
bool cmp(int* A,int* B){
    if(A[0]!=B[0])return A[0]<B[0];
    return A[1]<B[1];
}
void dfs(int i,int p){
    visit[i]=low[i]=t++;
    while(amt[i]-->0){
        if(!visit[adj[i][amt[i]]]){
            dfs(adj[i][amt[i]],i);
            low[i]=min(low[i],low[adj[i][amt[i]]]);
            if(low[adj[i][amt[i]]]>visit[i]){
                bridge[b][0]=i,bridge[b][1]=adj[i][amt[i]];
                if(bridge[b][0]>bridge[b][1])swap(bridge[b][0],bridge[b][1]);
                ans[b]=bridge[b];
                b++;
            }
        }else if(adj[i][amt[i]]!=p){
            low[i]=min(low[i],low[adj[i][amt[i]]]);
        }
    }
}
int main(){
    int i,j;
    while(scanf("%d %d",&n,&m)&&!(n==0&&m==0)){
        for(i=0;i<n;i++){
            amt[i]=0;
            visit[i]=0;
        }
        t=1;
        b=0;
        while(m-->0){
            scanf("%d %d",&i,&j);
            adj[i][amt[i]++]=j;
            adj[j][amt[j]++]=i;
        }
        for(i=0;i<n;i++){
            if(!visit[i]){
                dfs(i,i);
            }
        }
        sort(ans,ans+b,cmp);
        printf("%d",b);
        if(b>0)printf(" ");
        for(i=0;i<b;i++){
            printf("%d %d",ans[i][0],ans[i][1]);
            if(i!=b-1)printf(" ");
        }
        printf("\n");
    }
}
