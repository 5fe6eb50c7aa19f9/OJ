#include <cstdio>
#include <iostream>
using namespace std;
struct node{
    int l,r,lp,rp,sum;
};
int loc[100001];//location
int n;
node st[410000];//segment tree
int num;//node used number
int con(int i,int l,int r){
    st[i].l=l,st[i].r=r;
    if(l+1==r){
        st[i].sum=l<n?1:0;
        return st[i].sum;
    }
    int m=(l+r)/2;
    st[i].lp=num++,st[i].rp=num++;
    st[i].sum=con(st[i].lp,l,m)+con(st[i].rp,m,r);
    return st[i].sum;
}
void del(int i,int tar){
    if(st[i].l==tar&&st[i].r==tar+1){
        st[i].sum=0;
        return;
    }
    int m=(st[i].l+st[i].r)/2;
    if(tar<m){
        del(st[i].lp,tar);
    }else{
        del(st[i].rp,tar);
    }
    st[i].sum=st[st[i].lp].sum+st[st[i].rp].sum;
}
void ins(int i,int tar){
    if(st[i].l==tar&&st[i].r==tar+1){
        st[i].sum=1;
        return;
    }
    int m=(st[i].l+st[i].r)/2;
    if(tar<m){
        ins(st[i].lp,tar);
    }else{
        ins(st[i].rp,tar);
    }
    st[i].sum=st[st[i].lp].sum+st[st[i].rp].sum;
}
int que(int i,int ql,int qr){
    if(st[i].l==ql&&st[i].r==qr){
        return st[i].sum;
    }
    int m=(st[i].l+st[i].r)/2;
    if(qr<=m){
        return que(st[i].lp,ql,qr);
    }else if(ql>=m){
        return que(st[i].rp,ql,qr);
    }else{
        return que(st[i].lp,ql,m)+que(st[i].rp,m,qr);
    }
}
int main(){
    int t,i,j,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(i=0,j=n;i<n;i++,j--){
            loc[j]=i;
        }
        num=1;
        con(0,0,n+m);
        for(i=0;i<m;i++){
            scanf("%d",&j);
            printf("%d",que(0,loc[j],n+m)-1);
            if(i<m-1)printf(" ");
            del(0,loc[j]);
            ins(0,n+i);
            loc[j]=n+i;
        }
        printf("\n");
    }
}
