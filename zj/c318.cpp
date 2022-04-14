#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

struct node{
    int s,d;
    bool operator()(node& a,node& b){
        return a.s<b.s;
    }
};
priority_queue<node,vector<node>,node> heap;
int main(){
    int n,t,i,ans;
    node tmp;
    while(scanf("%d %d",&n,&t)==2){
        while(!heap.empty())heap.pop();
        while(n--){
            scanf("%d %d",&tmp.s,&tmp.d);
            heap.push(tmp);
        }
        for(i=0,ans=0;i<t;i++){
            if(heap.top().s>0){
                ans+=heap.top().s;
                tmp=heap.top();
                heap.pop();
                tmp.s-=tmp.d;
                heap.push(tmp);
            }
        }
        printf("%d\n",ans);
    }
}
