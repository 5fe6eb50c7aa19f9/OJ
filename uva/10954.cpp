#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
struct cmp{
    bool operator()(long long& a,long long& b){
        return a>b;
    }
};
int main(){
    long long i,n,a,b,ans;
    priority_queue<long long,vector<long long>,cmp> pq;
    while(scanf("%lld",&n)==1&&n){
        while(!pq.empty())pq.pop();
        for(i=0;i<n;i++){
            scanf("%d",&a);
            pq.push(a);
        }
        ans=0;
        while(pq.size()>1){
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            ans+=a+b;
            pq.push(a+b);
        }
        printf("%lld\n",ans);
    }
}
