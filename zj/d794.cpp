#include <iostream>
#include <cstdio>
using namespace std;

struct node{
    long long v;
    int i,ans;
};
node data[100000];
node tmp[100000];
void DC(int l,int r){
    if(l+1==r){
        return;
    }
    int m=(l+r)>>1,i,j,k;
    DC(l,m);
    DC(m,r);
    for(i=l,j=l,k=m;i<r;i++){
        if(k==r){
            tmp[i]=data[j++];
        }else if(j==m){
            data[k].ans+=j-l;
            tmp[i]=data[k++];
        }else if(data[j].v<data[k].v){
            data[k].ans+=j-l;
            tmp[i]=data[k++];
        }else{
            tmp[i]=data[j++];
        }
    }
    for(i=l;i<r;i++){
        data[i]=tmp[i];
    }
}
int main(){
    int n,i;
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++){
            scanf("%lld",&data[i].v);
            data[i].i=i;
            data[i].ans=0;
        }
        DC(0,n);
        for(i=0;i<n;i++){
            tmp[data[i].i]=data[i];
        }
        for(i=0;i<n;i++){
            printf("%d\n",tmp[i].ans+1);
        }
    }
}
