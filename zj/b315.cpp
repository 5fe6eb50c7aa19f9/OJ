#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int data[100000],n;
int lowerbound(int l,int r,int v){
    int ret=n,m;
    while(l<r){
        m=(l+r)>>1;
        if(data[m]<v){
            l=m+1;
        }else{
            ret=r=m;
        }
    }
    return ret;
}
int main(){
    int k,i,j,l,m,r,tmp,ans;
    while(scanf("%d %d",&n,&k)==2){
        for(i=0;i<n;i++)scanf("%d",data+i);
        sort(data,data+n);
        l=0,r=data[n-1]-data[0]+1;
        while(l<r){
            m=(l+r)>>1;
            for(i=0,tmp=0;i<n-1;i++){
                tmp+=n-lowerbound(i+1,n,data[i]+m);
            }
            if(tmp<k){
                r=m;
            }else{
                ans=m;
                l=m+1;
            }
        }
        printf("%d\n",ans);
    }
}
