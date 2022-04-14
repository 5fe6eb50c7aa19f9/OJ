#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define ll long long
struct node{
    int v,i;
    ll two;
};
node data[1000000];
node tmp[1000000];
ll ans;
void DC(int l,int r){
    if(l+1==r){
        data[l].two=0;
        data[l].i=l;
        return;
    }
    int m=(l+r)>>1,i,j,k;
    DC(l,m),DC(m,r);
    for(i=l,j=l,k=m;i<r;i++){
        if(j==m){
            tmp[i]=data[k++];
        }else if(k==r){
            tmp[i]=data[j++];
        }else if(data[j].v<=data[k].v){
            tmp[i]=data[j++];
        }else{
            data[k].two+=m-j;
            tmp[i]=data[k++];
        }
    }
    for(i=l;i<r;i++)data[i]=tmp[i];
}
void DC2(int l,int r){
    if(l+1==r){
        return;
    }
    int m=(l+r)>>1,i,j,k;
    ll acc=0;
    DC2(l,m),DC2(m,r);
    for(i=l;i<m;i++)acc+=data[i].two;
    for(i=l,j=l,k=m;i<r;i++){
        if(j==m){
            tmp[i]=data[k++];
        }else if(k==r){
            tmp[i]=data[j++];
        }else if(data[j].v<=data[k].v){
            acc-=data[j].two;
            tmp[i]=data[j++];
        }else{
            ans+=acc;
            tmp[i]=data[k++];
        }
    }
    for(i=l;i<r;i++)data[i]=tmp[i];
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&data[i].v);
    }
    DC(0,n);
    for(i=0;i<n;i++){
        data[tmp[i].i]=tmp[i];
    }
    DC2(0,n);
    printf("%lld\n",ans);
}
