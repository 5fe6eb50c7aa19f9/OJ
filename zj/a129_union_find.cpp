#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct edge{
    int a,b,w;
    bool operator<(edge& other){
        return w<other.w;
    }
};
edge e[200000];
int p[100000];
int Find(int i){
    return p[i]==i?i:(p[i]=Find(p[i]));
}
int main(){
    int n,m,i,j,k,tmp;
    long long ans;
    while(scanf("%d %d",&n,&m)==2){
        for(i=0;i<n;i++)p[i]=i;
        for(i=0;i<m;i++){
            scanf("%d %d %d",&e[i].a,&e[i].b,&e[i].w);
        }
        sort(e,e+m);
        for(i=tmp=0,ans=0;i<m;i++){
            j=Find(e[i].a),k=Find(e[i].b);
            if(j!=k){
                tmp++;
                ans+=e[i].w;
                p[j]=k;
            }
        }
        printf("%lld\n",tmp==n-1?ans:-1);
    }
}
