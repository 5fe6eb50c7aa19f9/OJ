#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
struct node{
    int l,r;
};
struct cmp{
    bool operator()(node& a,node& b){
        if(a.l!=b.l)return a.l>b.l;
        return a.r>b.r;
    }
};

priority_queue<node,vector<node>,cmp> pq;
int main(){
    int n,l,r,i,ans;
    node tmp;
    while(scanf("%d",&n)==1){
        while(!pq.empty())pq.pop();
        for(i=0;i<n;i++){
            scanf("%d %d",&l,&r);
            pq.push(node{l,r});
        }
        ans=0;
        while(!pq.empty()){
            tmp=pq.top();
            pq.pop();
            while(!pq.empty()&&tmp.r>=pq.top().l){
                tmp.r=max(tmp.r,pq.top().r);
                pq.pop();
            }
            ans+=tmp.r-tmp.l;
        }
        printf("%d\n",ans);
    }
}
