#include <cstdio>
#include <cstring>
using namespace std;

struct ST{
    int l,r,lt,rt,num;
};
ST st[400000];
int used;
void build(int i,int l,int r){
    st[i].l=l,st[i].r=r,st[i].num=0;
    if(l+1==r){
        return;
    }
    int m=(l+r)>>1;
    st[i].lt=used++,st[i].rt=used++;
    build(st[i].lt,l,m);
    build(st[i].rt,m,r);
}
void edit(int i,int x){
    if(st[i].l==x&&st[i].r==x+1){
        st[i].num=!st[i].num;
        return;
    }
    int m=(st[i].l+st[i].r)>>1;
    if(x<m){
        edit(st[i].lt,x);
    }else{
        edit(st[i].rt,x);
    }
    st[i].num=st[st[i].lt].num+st[st[i].rt].num;
}
int query(int i,int ql,int qr){
    if(st[i].l==ql&&st[i].r==qr){
        return st[i].num;
    }
    int m=(st[i].l+st[i].r)>>1;
    if(qr<=m){
        return query(st[i].lt,ql,qr);
    }else if(ql>=m){
        return query(st[i].rt,ql,qr);
    }else{
        return query(st[i].lt,ql,m)+query(st[i].rt,m,qr);
    }
}
int main(){
    int n,q,v,ql,qr;
    while(scanf("%d %d",&n,&q)==2){
        used=1;
        build(0,0,n);
        while(q--){
            scanf("%d",&v);
            if(v==1){
                scanf("%d",&v);
                edit(0,v-1);
            }else{
                scanf("%d %d",&ql,&qr);
                printf("%d\n",query(0,ql-1,qr)%2);
            }
        }
    }
}
