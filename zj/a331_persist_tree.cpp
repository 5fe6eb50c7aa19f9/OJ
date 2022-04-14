#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct persist_tree{
    struct Node{
        int l,r,lnum,rnum,lp,rp;
    };
    Node node[2000000];
    int pos[100001];
    int used;
    void initialize(int n){
        pos[0]=0;
        used=0;
        build(used++,0,n);
    }
    void build(int i,int l,int r){
        node[i].l=l,node[i].r=r;
        node[i].lnum=node[i].rnum=0;
        if(l+1==r)return;
        node[i].lp=used++,node[i].rp=used++;
        int m=(l+r)>>1;
        build(node[i].lp,l,m),build(node[i].rp,m,r);
    }
    void add(int i,int j,int x){
        node[i]=node[j];
        if(node[i].l+1==node[i].r)return;
        int m=(node[i].l+node[i].r)>>1;
        if(x<m){
            node[i].lp=used++;
            node[i].lnum++;
            add(node[i].lp,node[j].lp,x);
        }else{
            node[i].rp=used++;
            node[i].rnum++;
            add(node[i].rp,node[j].rp,x);
        }
    }
    int query(int i,int j,int x){
        if(node[i].l+1==node[i].r)return node[i].l;
        if(node[i].lnum-node[j].lnum>=x){
            return query(node[i].lp,node[j].lp,x);
        }else{
            return query(node[i].rp,node[j].rp,x-node[i].lnum+node[j].lnum);
        }
    }
};
persist_tree pt;
int data[100000];
int* ptr[100000];
int Hash[100000];
bool cmp(int* a,int* b){
    return *a<*b;
}
int main(){
    int n,m,i,j,k;
    while(scanf("%d %d",&n,&m)==2){
        for(i=0;i<n;i++){
            scanf("%d",data+i);
            ptr[i]=data+i;
        }
        sort(ptr,ptr+n,cmp);
        for(i=0;i<n;i++){
            Hash[i]=*ptr[i];
            *ptr[i]=i;
        }
        pt.initialize(n);
        for(i=1;i<=n;i++){
            pt.pos[i]=pt.used++;
            pt.add(pt.pos[i],pt.pos[i-1],data[i-1]);
        }
        while(m--){
            scanf("%d %d %d",&i,&j,&k);
            printf("%d\n",Hash[pt.query(pt.pos[j],pt.pos[i-1],k)]);
        }
    }
}
