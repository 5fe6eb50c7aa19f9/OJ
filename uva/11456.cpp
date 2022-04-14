#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int data[2000];
int lis[2000];
int lds[2000];
int pos[2000];
int main(){
    int t,n,i,j,ans,l,r,mid,len;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",data+i);
        }
        pos[0]=0x80000000;
        len=1;
        //calculate each LIS of data[i~n-1]
        for(i=n-1;i>=0;i--){
            l=0,r=len+1;//[l,r)
            while(l<r){
                mid=(l+r)/2;
                if(mid==0||pos[mid-1]>data[i]){
                    lis[i]=mid;
                    l=mid+1;
                }else if(pos[mid-1]==data[i]){
                    lis[i]=mid-1;
                    break;
                }else{
                    r=mid;
                }
            }
            if(lis[i]==len)len++;
            pos[lis[i]]=data[i];
        }
        pos[0]=0x7fffffff;
        len=1;
        //calculate each LDS of data[i~n-1]
        for(i=n-1;i>=0;i--){
            l=0,r=len+1;
            while(l<r){
                mid=(l+r)/2;
                if(mid==0||pos[mid-1]<data[i]){
                    lds[i]=mid;
                    l=mid+1;
                }else if(pos[mid-1]==data[i]){
                    lds[i]=mid-1;
                    break;
                }else{
                    r=mid;
                }
            }
            if(lds[i]==len)len++;
            pos[lds[i]]=data[i];
        }
        ans=0;
        for(i=0;i<n;i++){
            ans=max(ans,1+lis[i]+lds[i]);
        }
        printf("%d\n",ans);
    }
}

