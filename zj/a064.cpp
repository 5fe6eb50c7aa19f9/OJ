#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int data[100];
int abc[1000000];//a*b+c
int main(){
    int n,i,j,k,tmp,l,r,m,flag;
    long long ans;
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++){
            scanf("%d",data+i);
        }
        for(i=tmp=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    abc[tmp++]=data[i]*data[j]+data[k];
                }
            }
        }
        sort(abc,abc+n*n*n);
        ans=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    if(data[k]==0)continue;
                    tmp=(data[i]+data[j])*data[k];//(f+e)*d
                    l=0,r=n*n*n,flag=-1;
                    while(l<r){
                        m=(l+r)>>1;
                        if(tmp<abc[m]){
                            r=m;
                        }else if(tmp>abc[m]){
                            l=m+1;
                        }else{
                            flag=m;
                            r=m;
                        }
                    }
                    if(flag==-1)continue;
                    ans-=flag;
                    l=flag,r=n*n*n;
                    while(l<r){
                        m=(l+r)>>1;
                        if(tmp<abc[m]){
                            r=m;
                        }else if(tmp>abc[m]){
                            l=m+1;
                        }else{
                            flag=m;
                            l=m+1;
                        }
                    }
                    ans+=flag+1;
                }
            }
        }
        printf("%lld\n",ans);
    }
}
