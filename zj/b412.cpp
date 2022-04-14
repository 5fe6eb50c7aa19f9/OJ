#include <iostream>
#include <cstdio>
using namespace std;

int data[100000];
int tree[20][100000];
int a,b;
void MS(int l,int r,int level){
    if(l+1==r){
        tree[level][l]=data[l];
        return;
    }
    int m=(l+r)>>1,i,j,k;
    MS(l,m,level+1);
    MS(m,r,level+1);
    for(i=l,j=l,k=m;i<r;i++){
        if(j==m){
            tree[level][i]=data[k++];
        }else if(k==r){
            tree[level][i]=data[j++];
        }else if(data[j]<data[k]){
            tree[level][i]=data[j++];
        }else{
            tree[level][i]=data[k++];
        }
    }
    for(i=l;i<r;i++){
        data[i]=tree[level][i];
    }
}
int query(int l,int r,int level,int ql,int qr){
    if(l==ql&&r==qr){
        int lb=-1,ub=-1,m,tmp=r;
        while(l<r){
            m=(l+r)>>1;
            if(tree[level][m]<a){
                l=m+1;
            }else if(tree[level][m]>=a){
                lb=m;
                r=m;
            }
        }
        if(lb==-1)return 0;
        l=lb,r=tmp;
        while(l<r){
            m=(l+r)>>1;
            if(tree[level][m]<=b){
                ub=m;
                l=m+1;
            }else if(tree[level][m]>b){
                r=m;
            }
        }
        if(lb<=ub)return ub-lb+1;
        return 0;
    }
    int m=(l+r)>>1;
    if(qr<=m){
        return query(l,m,level+1,ql,qr);
    }else if(ql>=m){
        return query(m,r,level+1,ql,qr);
    }else{
        return query(l,m,level+1,ql,m)+query(m,r,level+1,m,qr);
    }
}
int main(){
    int n,m,i,ql,qr;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",data+i);
    }
    MS(0,n,0);
    while(m--){
        scanf("%d %d %d %d",&ql,&qr,&a,&b);
        printf("%d\n",query(0,n,0,ql-1,qr));
    }
}
