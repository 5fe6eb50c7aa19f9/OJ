#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct node{
    int sum,now,last;
};
struct cmp{
    bool operator()(node& a,node& b){
        return a.sum>b.sum;
    }
};
bool cmp2(node& a,node& b){
    if(a.sum!=b.sum)return a.sum<b.sum;
    if(a.last!=b.last)return a.last<b.last;
    return a.now<b.now;
}
priority_queue<node,vector<node>,cmp> pq;
int main(){
    int t,T,n,i,j,k,num;
    char buff;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d",&n);
        int e[n][n];
        bool s[n];
        node ans[n];
        num=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&e[i][j]);
                if(j<n-1)scanf("%c",&buff);
            }
            s[i]=0;
        }
        num=0;
        pq.push(node{0,0});
        while(!pq.empty()){
            i=pq.top().now;
            k=pq.top().sum;
            if(!s[i]){
                ans[num++]=pq.top();
                pq.pop();
                s[i]=1;
                for(j=0;j<n;j++){
                    if(e[i][j]!=0)pq.push(node{e[i][j],j,i});
                }
            }else{
                pq.pop();
            }
        }
        for(i=0;i<num;i++){
            if(ans[i].last>ans[i].now)swap(ans[i].last,ans[i].now);
        }
        sort(ans,ans+num,cmp2);
        printf("Case %d:\n",t);
        for(i=1;i<num;i++)printf("%c-%c %d\n",ans[i].last+'A',ans[i].now+'A',ans[i].sum);
    }
}
