//"segment tree" + "sparse table" test
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct ST{
    int x1,x2,lt,rt;
    int table[10][500];//table[a][b]=max value of [b,b+a)
};
int data[500][500];
int tmp[501];
ST st[1000];
int N,M,num;
void build(int i,int x1,int x2){
    st[i].x1=x1,st[i].x2=x2;
    if(x1+1==x2){
        for(int wid=0;(1<<wid)<=M;wid++){
            for(int beg=0;beg+(1<<wid)<=M;beg++){
                if(wid==0){
                    st[i].table[wid][beg]=data[x1][beg];
                }else{
                    st[i].table[wid][beg]=max(st[i].table[wid-1][beg],st[i].table[wid-1][beg+(1<<wid-1)]);
                }
            }
        }
        return;
    }
    int m=(x1+x2)>>1,lt=num++,rt=num++;
    st[i].lt=lt,st[i].rt=rt;
    build(st[i].lt,x1,m);
    build(st[i].rt,m,x2);
    for(int wid=0;(1<<wid)<=M;wid++){
        for(int beg=0;beg+(1<<wid)<=M;beg++){
            st[i].table[wid][beg]=max(st[lt].table[wid][beg],st[rt].table[wid][beg]);
        }
    }
}
int query(int i,int qx1,int qy1,int qx2,int qy2){
    if(st[i].x1==qx1&&st[i].x2==qx2){
        int wid=tmp[qy2-qy1];
        return max(st[i].table[wid][qy1],st[i].table[wid][qy2-(1<<wid)]);
    }
    int m=(st[i].x1+st[i].x2)>>1;
    if(qx1>=m){
        return query(st[i].rt,qx1,qy1,qx2,qy2);
    }else if(qx2<=m){
        return query(st[i].lt,qx1,qy1,qx2,qy2);
    }else{
        return max(query(st[i].lt,qx1,qy1,m,qy2),query(st[i].rt,m,qy1,qx2,qy2));
    }
}
int main(){
    int i,j,q,qx1,qy1,qx2,qy2;
    for(i=1,j=0;i<=500;i++){
        if(i>(1<<j+1))j++;
        tmp[i]=j;
    }
    while(scanf("%d %d",&N,&M)==2){
        for(i=0;i<N;i++){
            for(j=0;j<M;j++)scanf("%d",data[i]+j);
        }
        num=0;
        build(num++,0,N);
        scanf("%d",&q);
        while(q--){
            scanf("%d %d %d %d",&qx1,&qy1,&qx2,&qy2);
            printf("%d\n",query(0,qx1-1,qy1-1,qx2,qy2));
        }
    }
}
