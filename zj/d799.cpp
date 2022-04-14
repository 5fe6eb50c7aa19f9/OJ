#include <cstdio>
#include <iostream>
using namespace std;
struct ST{
    int l,r,lp,rp;
    long long v,delta;
};
ST st[1000000];
int num;
int data[500000];
void cons(int i,int l,int r){
    st[i].l=l,st[i].r=r,st[i].delta=0;
    if(l+1==r){
        st[i].v=data[l];
        return;
    }
    int m=(l+r)/2;
    st[i].lp=num++,st[i].rp=num++;
    cons(st[i].lp,l,m);
    cons(st[i].rp,m,r);
    st[i].v=st[st[i].lp].v+st[st[i].rp].v;
}
void edit(int i,int el,int er,int delta){
    if(st[i].l==el&&st[i].r==er){
        st[i].delta+=delta;
        return;
    }
    int m=(st[i].l+st[i].r)/2;
    if(er<=m){
        edit(st[i].lp,el,er,delta);
    }else if(el>=m){
        edit(st[i].rp,el,er,delta);
    }else{
        edit(st[i].lp,el,m,delta);
        edit(st[i].rp,m,er,delta);
    }
    int lp=st[i].lp,rp=st[i].rp;
    st[i].v=st[lp].v+st[lp].delta*(st[lp].r-st[lp].l)+st[rp].v+st[rp].delta*(st[rp].r-st[rp].l);
}
long long quer(int i,int ql,int qr){
    if(st[i].l==ql&&st[i].r==qr){
        return st[i].v+st[i].delta*(qr-ql);
    }
    int m=(st[i].l+st[i].r)/2;
    if(qr<=m){
        return quer(st[i].lp,ql,qr)+st[i].delta*(qr-ql);
    }else if(ql>=m){
        return quer(st[i].rp,ql,qr)+st[i].delta*(qr-ql);
    }else{
        return quer(st[i].lp,ql,m)+quer(st[i].rp,m,qr)+st[i].delta*(qr-ql);
    }
}
int main(){
    int n,i,v,x,y,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",data+i);
    num=1;
    cons(0,0,n);
    scanf("%d",&n);
    while(n--){
        scanf("%d",&v);
        if(v==1){
            scanf("%d %d %d",&x,&y,&k);
            edit(0,x-1,y,k);
        }else{
            scanf("%d %d",&x,&y);
            printf("%lld\n",quer(0,x-1,y));
        }
    }
}
