#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
struct Persist_Tree{
    struct Node{
        int l,r,lnum,rnum,li,ri;
    };
    Node node[2000000];
    int used;
    int pos[100001];
    void build(int i,int l,int r){
        node[i].l=l,node[i].r=r;
        node[i].lnum=node[i].rnum=0;
        if(l+1==r)return;
        int m=(l+r)>>1;
        node[i].li=used++,node[i].ri=used++;
        build(node[i].li,l,m),build(node[i].ri,m,r);
    }
    void add(int i,int j,int x){
        node[i]=node[j];
        if(node[i].l+1==node[i].r)return;
        int m=(node[i].l+node[i].r)>>1;
        if(x<m){
            node[i].lnum++;
            node[i].li=used++;
            add(node[i].li,node[j].li,x);
        }else{
            node[i].rnum++;
            node[i].ri=used++;
            add(node[i].ri,node[j].ri,x);
        }
    }
    int query(int i,int j,int x){
        if(node[i].l+1==node[i].r)return 0;
        int m=(node[i].l+node[i].r)>>1;
        if(x<m){
            return node[i].rnum-node[j].rnum+query(node[i].li,node[j].li,x);
        }else{
            return query(node[i].ri,node[j].ri,x);
        }
    }
};
Persist_Tree pt;
int main(){
    int i,j,m,n,a,b,c,d;
    pt.pos[0]=0;
    while(scanf("%d %d",&n,&m)==2){
        pt.used=0;
        pt.build(pt.used++,0,n+1);
        for(i=0;i<n;i++){
            scanf("%d",&j);
            pt.pos[i+1]=pt.used++;
            pt.add(pt.pos[i+1],pt.pos[i],j);
        }
        while(m--){
            scanf("%d %d %d %d",&a,&b,&c,&d);
            printf("%d\n",pt.query(pt.pos[b],pt.pos[a-1],c-1)-pt.query(pt.pos[b],pt.pos[a-1],d));
        }
    }
}
