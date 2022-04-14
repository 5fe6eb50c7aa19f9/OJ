#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int data[100000];
long long acc[100000];
long long lim=100000,delta,target=lim;
int tree[20][100000];
void MS(int l,int r,int level){
    if(l+1==r){
        tree[level][l]=data[l];
        return;
    }
    int m=(l+r)>>1,i,j,k;
    MS(l,m,level+1),MS(m,r,level+1);
    for(i=l,j=l,k=m;i<r;i++){
        if(j==m){
            tree[level][i]=tree[level+1][k++];
        }else if(k==r){
            tree[level][i]=tree[level+1][j++];
        }else if(tree[level+1][j]<tree[level+1][k]){
            tree[level][i]=tree[level+1][j++];
        }else{
            tree[level][i]=tree[level+1][k++];
        }
    }
}
int query(int l,int r,int ql,int qr,int level){
    int ret=0,m;
    if(l==ql&&r==qr){
        int pos=-1;
        while(l<r){
            m=(l+r)>>1;
            if(target>=tree[level][m]){
                l=m+1;
            }else{
                pos=m;
                r=m;
            }
        }
        if(pos!=-1){
            ret=qr-pos;
        }
        return ret;
    }
    m=(l+r)>>1;
    if(qr<=m){
        ret=query(l,m,ql,qr,level+1);
    }else if(ql>=m){
        ret=query(m,r,ql,qr,level+1);
    }else{
        ret=query(l,m,ql,m,level+1)+query(m,r,m,qr,level+1);
    }
    return ret;
}
int main(){
    int i,j,n,m;
    long long ans,test;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",data+i);
        acc[i]=data[i];
        if(i>0)acc[i]+=acc[i-1];
    }
    MS(0,n,0);
    while(m--){
        scanf("%d",&i);
        if(i==1){
            scanf("%d",&i);
            delta=(delta+i)%lim;
            target=lim-delta;
        }else{
            scanf("%d %d",&i,&j);
            i--;
            ans=acc[j-1];
            if(i)ans-=acc[i-1];
            ans+=delta*(j-i)-lim*query(0,n,i,j,0);
            printf("%lld\n",ans);
        }
    }
}
