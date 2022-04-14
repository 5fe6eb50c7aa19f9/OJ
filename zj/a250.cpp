#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define ll long long
struct node{
    ll i,v;
    bool operator<(node &b){
        if(v!=b.v)return v<b.v;
        return i<b.i;
    }
};
node arr[100000];
int main(){
    ll i,j,n,mod,a,b;
    while(scanf("%lld",&n)==1&&n){
        for(i=0;i<n;i++){
            scanf("%lld",&arr[i].v);
            arr[i].i=i;
        }
        scanf("%lld",&mod);
        for(i=0;i<n;i++){
            if(i)arr[i].v+=arr[i-1].v;
            arr[i].v%=mod;
            if(arr[i].v<0)arr[i].v+=mod;
        }
        sort(arr,arr+n);
        a=b=1e12;
        if(arr[0].v==0){
            a=-1;
            b=arr[0].i;
        }
        for(i=0;i+1<n;i++){
            if(arr[i].v==arr[i+1].v){
                if(arr[i].i<a||arr[i].i==a&&arr[i+1].i<b){
                    a=arr[i].i;
                    b=arr[i+1].i;
                }
            }
        }
        if(a==1e12){
            printf("no solutions.\n");
        }else{
            printf("%lld %lld\n",a+2,b+1);
        }
    }
}
