#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct event{
    int l,r,v;
    bool operator<(event& o){
        return r<o.r;
    }
};
event data[50000];
int maxsum[50000];
int main(){
    int T,t,n,i,j,l,r,m;
    data[0].l=data[0].r=-1;
    data[0].v=0;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d %d %d",&data[i].l,&data[i].r,&data[i].v);
            data[i].r+=data[i].l-1;
        }
        sort(data+1,data+n+1);
        for(i=1;i<=n;i++){
            l=0,r=i;
            while(l<r){
                m=(l+r)>>1;
                if(data[i].l<=data[m].r){
                    r=m;
                }else if(data[i].l>data[m].r){
                    j=m;
                    l=m+1;
                }
            }
            maxsum[i]=max(data[i].v+maxsum[j],maxsum[i-1]);
        }
        printf("Case %d: %d\n",t,maxsum[n]);
    }
}
