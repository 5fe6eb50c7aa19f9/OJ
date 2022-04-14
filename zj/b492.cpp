#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

long long data[50000];
long long tmp[50000];
long long tree[17][50000];
long long mult[17][50000];
int num;
void MS(int l,int r,int deep){
    if(l+1==r){
        tree[deep][l]=mult[deep][l]=data[l];
        return;
    }
    int m=(l+r)>>1,i,j,k;
    MS(l,m,deep+1);
    MS(m,r,deep+1);
    for(i=l,j=l,k=m;i<r;i++){
        if(j==m){
            tmp[i]=data[k++];
        }else if(k==r){
            tmp[i]=data[j++];
        }else if(data[j]<data[k]){
            tmp[i]=data[j++];
        }else{
            tmp[i]=data[k++];
        }
    }
    for(i=l;i<r;i++){
        data[i]=tree[deep][i]=mult[deep][i]=tmp[i];
        if(i>l)mult[deep][i]=(mult[deep][i]*mult[deep][i-1])%1000000007;
    }
}
long long query(int l,int r,int deep,int ql,int qr,long long k){
    if(l==ql&&r==qr){
        int m,flag=-1;
        while(l<r){
            m=(l+r)>>1;
            if(tree[deep][m]<=k){
                flag=m;
                l=m+1;
            }else{
                r=m;
            }
        }
        if(flag==-1){
            return 1;
        }else{
            num+=flag-ql+1;
            return mult[deep][flag];
        }
    }
    int m=(l+r)>>1;
    if(qr<=m){
        return query(l,m,deep+1,ql,qr,k);
    }else if(ql>=m){
        return query(m,r,deep+1,ql,qr,k);
    }else{
        return (query(l,m,deep+1,ql,m,k)*query(m,r,deep+1,m,qr,k))%1000000007;
    }
}
int main(){
    int n,q,i,ql,qr,k,satisfy;
    while(scanf("%d %d",&n,&q)==2){
        for(i=0;i<n;i++){
            scanf("%lld",data+i);
        }
        MS(0,n,0);
        while(q--){
            scanf("%d %d %d",&ql,&qr,&k);
            num=0;
            satisfy=query(0,n,0,ql-1,qr,k);
            if(num==0){
                printf("0 0\n");
            }else{
                printf("%d %d\n",num,satisfy);
            }
        }
    }
}
