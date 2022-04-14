#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

long long acc[100001];
long long a,b;
long long delta[100001];
long long tmp[100001];
long long DC(long long l,long long r,bool flag){//divide and conquer [l,r]
    long long ans=0;
    if(l==r){
        if(!flag&&acc[l]>=a*l){
            ans++;
        }else if(flag&&acc[l]>b*l){
            ans++;
        }
        if(!flag){
            delta[l]=acc[l]-a*l;
        }else{
            delta[l]=acc[l]-b*l;
        }
        return ans;
    }
    long long m=(l+r)>>1,i,j,k;
    ans+=DC(l,m,flag)+DC(m+1,r,flag);
    for(i=m+1,j=l;i<=r;i++){
        if(!flag&&delta[i]-delta[j]<0){
            continue;
        }
        if(flag&&delta[i]-delta[j]<=0){
            continue;
        }
        while(!flag&&j+1<=m&&delta[i]-delta[j+1]>=0)j++;
        while(flag&&j+1<=m&&delta[i]-delta[j+1]>0)j++;
        ans+=j-l+1;
    }
    for(i=l,j=l,k=m+1;i<=r;i++){
        if(j==m+1){
            tmp[i]=delta[k++];
        }else if(k==r+1){
            tmp[i]=delta[j++];
        }else if(delta[j]<delta[k]){
            tmp[i]=delta[j++];
        }else{
            tmp[i]=delta[k++];
        }
    }
    for(i=l;i<=r;i++){
        delta[i]=tmp[i];
    }
    return ans;
}
int main(){
    int n,i;
    while(scanf("%d",&n)==1){
        scanf("%lld %lld",&a,&b);
        for(i=1;i<=n;i++){
            scanf("%lld",acc+i);
            acc[i]+=acc[i-1];
        }
        printf("%lld\n",DC(1,n,0)-DC(1,n,1));//num(sum>=a) - num(sum>b)
    }
}
