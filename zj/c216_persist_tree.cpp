#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

struct persistent_tree{
    struct Node{
        int l,r,lnum,rnum,lp,rp;
    };
    Node node[2000000];
    int used;
    int pos[100001];
    void initial(){
        used=0;
        pos[0]=0;
        build(used++,0,100001);
    }
    void build(int i,int l,int r){
        node[i].l=l,node[i].r=r;
        node[i].lnum=node[i].rnum=0;
        if(l+1==r)return;
        int m=(l+r)>>1;
        node[i].lp=used++,node[i].rp=used++;
        build(node[i].lp,l,m),build(node[i].rp,m,r);
    }
    void add(int i,int j,int x){
        node[i]=node[j];
        if(node[i].l+1==node[i].r)return;
        int m=(node[i].l+node[i].r)>>1;
        if(x<m){
            node[i].lnum++;
            node[i].lp=used++;
            add(node[i].lp,node[j].lp,x);
        }else{
            node[i].rnum++;
            node[i].rp=used++;
            add(node[i].rp,node[j].rp,x);
        }
    }
    int query(int i,int j,int x){
        if(node[i].l+1==node[i].r)return 0;
        int m=(node[i].l+node[i].r)>>1;
        if(x<m){
            return node[i].rnum-node[j].rnum+query(node[i].lp,node[j].lp,x);
        }else{
            return query(node[i].rp,node[j].rp,x);
        }
    }
};
persistent_tree pt;
long long data[100000];
long long sum[100000];
long long lim=100000,delta,target=lim,ans;
int main(){
    int i,j,n,m;
    pt.initial();
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%lld",data+i);
        pt.pos[i+1]=pt.used++;
        pt.add(pt.pos[i+1],pt.pos[i],data[i]);
        sum[i]=data[i];
        if(i>0)sum[i]+=sum[i-1];
    }
    while(m--){
        scanf("%d",&i);
        if(i==1){
            scanf("%d",&i);
            delta=(delta+i)%lim;
            target=lim-delta;
        }else{
            scanf("%d %d",&i,&j);
            i--;
            ans=sum[j-1]+delta*(j-i);
            if(i)ans-=sum[i-1];
            printf("%lld\n",ans-lim*pt.query(pt.pos[j],pt.pos[i],target));
        }
    }
}
