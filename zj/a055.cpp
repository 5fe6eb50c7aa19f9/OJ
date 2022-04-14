#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct ST{
    int lnum,rnum,l,r,lp,rp;
};
ST st[170000];
int used;
int data[85000];
int ans[85000];
int build(int i,int l,int r){
    st[i].l=l,st[i].r=r;
    if(l+1==r){
        st[i].lnum=1,st[i].rnum=0;
        return 1;
    }
    int m=(l+r)>>1;
    st[i].lp=used++,st[i].rp=used++;
    st[i].lnum=build(st[i].lp,l,m);
    st[i].rnum=build(st[i].rp,m,r);
    return st[i].lnum+st[i].rnum;
}
int query(int i,int x){
    if(st[i].l+1==st[i].r){
        st[i].lnum--;
        return st[i].l;
    }
    int ret;
    if(st[i].lnum<x){
        ret=query(st[i].rp,x-st[i].lnum);
        st[i].rnum--;
    }else{
        ret=query(st[i].lp,x);
        st[i].lnum--;
    }
    return ret;
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    used=0;
    build(used++,1,n+1);
    for(i=0;i<n-1;i++){
        scanf("%d",ans+i);
    }
    for(i=n-2;i>=0;i--){
        ans[i]=query(0,ans[i]+1);
    }
    printf("%d\n",query(0,1));
    for(i=0;i<n-1;i++)printf("%d\n",ans[i]);
}
