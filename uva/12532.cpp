#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

struct node{
    int l,r,v,lp,rp;
};
int data[100000];
node st[200000];
int num;
int build(int l,int r){
    int i=num++;
    st[i].l=l,st[i].r=r;
    if(l+1==r){
        if(data[l]<0){
            st[i].v=-1;
        }else{
            st[i].v=data[l]!=0;
        }
    }else{
        int m=(l+r)>>1;
        st[i].lp=build(l,m);
        st[i].rp=build(m,r);
        st[i].v=st[st[i].lp].v*st[st[i].rp].v;
    }
    return i;
}
void edit(int i,int p,int v){
    if(st[i].l==p&&st[i].r==p+1){
        if(v<0){
            st[i].v=-1;
        }else{
            st[i].v=v!=0;
        }
    }else{
        int m=(st[i].l+st[i].r)>>1;
        if(p<m){
            edit(st[i].lp,p,v);
        }else{
            edit(st[i].rp,p,v);
        }
        st[i].v=st[st[i].lp].v*st[st[i].rp].v;
    }
}
int query(int i,int ql,int qr){
    if(st[i].l==ql&&st[i].r==qr){
        return st[i].v;
    }
    int m=(st[i].l+st[i].r)>>1;
    if(qr<=m){
        return query(st[i].lp,ql,qr);
    }else if(ql>=m){
        return query(st[i].rp,ql,qr);
    }else{
        return query(st[i].lp,ql,m)*query(st[i].rp,m,qr);
    }
}
int main(){
    int n,m,i,j,ret;
    char cmd;
    while(scanf("%d %d",&n,&m)==2){
        for(i=0;i<n;i++)scanf("%d%*c",data+i);
        num=0;
        build(0,n);
        while(m--){
            scanf("%c %d %d%*c",&cmd,&i,&j);
            if(cmd=='C'){
                edit(0,i-1,j);
            }else{
                switch(query(0,i-1,j)){
                    case -1:printf("-");break;
                    case 0:printf("0");break;
                    case 1:printf("+");break;
                }
            }
        }
        printf("\n");
    }
}
