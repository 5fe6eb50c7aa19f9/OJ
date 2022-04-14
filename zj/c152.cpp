#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define inf 0x7fffffff
struct node{
    int next,d;
    float t;//time
};
struct cmp{
    bool operator()(const node& a,const node& b){
        if(a.t==0&&b.t==0)return a.d>b.d;//for p1
        return a.t>b.t;//for p2
    }
};
vector<node> data[10001];
priority_queue<node,vector<node>,cmp> bfs;
void acess(int& M){
    int a,b,d,v;
    node tmp;
    for(int i=0;i<M;i++){
        scanf("%d %d %d %d",&a,&b,&d,&v);
        tmp.next=b,tmp.d=d,tmp.t=(float)d/(float)v;
        data[a].push_back(tmp);
        tmp.next=a;
        data[b].push_back(tmp);
    }
}
int p1(int& A,int &B,int& N){
    while(!bfs.empty())bfs.pop();
    node tmp;
    tmp.next=A,tmp.d=0,tmp.t=0;
    bfs.push(tmp);
    vector<int> ans(N+1,inf);
    while(bfs.top().next!=B){
        if(bfs.top().d<ans[bfs.top().next]){
            ans[bfs.top().next]=bfs.top().d;
            for(vector<node>::iterator i=data[bfs.top().next].begin();i!=data[bfs.top().next].end();i++){
                tmp.next=i->next,tmp.d=bfs.top().d+i->d,tmp.t=0;
                bfs.push(tmp);
            }
        }
        bfs.pop();
    }
    return bfs.top().d;
}
int p2(int& A,int &B,int& N){
    while(!bfs.empty())bfs.pop();
    node tmp;
    tmp.next=A,tmp.d=0,tmp.t=0;
    bfs.push(tmp);
    vector<float> ans(N+1,inf);
    while(bfs.top().next!=B){
        if(bfs.top().t<ans[bfs.top().next]){
            ans[bfs.top().next]=bfs.top().t;
            for(vector<node>::iterator i=data[bfs.top().next].begin();i!=data[bfs.top().next].end();i++){
                tmp.next=i->next,tmp.d=bfs.top().d+i->d,tmp.t=bfs.top().t+i->t;
                bfs.push(tmp);
            }
        }
        bfs.pop();
    }
    return bfs.top().d;
}
int main(){
    int i,j,T,N,M,A,B;
    scanf("%d",&T);
    while(T-->0){
        scanf("%d %d %d %d",&N,&M,&A,&B);
        acess(M);
        printf("%d ",p1(A,B,N));
        printf("%d\n",p2(A,B,N));
        for(i=0;i<=N;i++)data[i].clear();
    }
}
