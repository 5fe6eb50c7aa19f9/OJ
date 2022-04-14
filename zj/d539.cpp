#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct ST{
    int l,r,lp,rp,v;
};
ST st[1000000];
int amt;
int data[500000];
void con(int i,int l,int r){
    st[i].l=l,st[i].r=r;
    if(l+1==r){
        st[i].v=data[l];
        return;
    }
    int m=(l+r)/2;
    st[i].lp=amt++,st[i].rp=amt++;
    con(st[i].lp,l,m);
    con(st[i].rp,m,r);
    st[i].v=max(st[st[i].lp].v,st[st[i].rp].v);
}
int que(int i,int l,int r){
    if(st[i].l==l&&st[i].r==r){
        return st[i].v;
    }
    int m=(st[i].l+st[i].r)/2;
    if(r<=m){
        return que(st[i].lp,l,r);
    }else if(l>=m){
        return que(st[i].rp,l,r);
    }else{
        return max(que(st[i].lp,l,m),que(st[i].rp,m,r));
    }
}
int main(){
    int n,i,j;
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++){
            scanf("%d",data+i);
        }
        amt=1;
        con(0,0,n);
        scanf("%d",&n);
        while(n--){
            scanf("%d %d",&i,&j);
            if(i>j)swap(i,j);
            printf("%d\n",que(0,i-1,j));
        }
    }
}

