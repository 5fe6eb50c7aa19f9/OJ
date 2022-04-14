#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int data[5001];
int sum[5001];
int main(){
    int t,i,j,k,l,r,n,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",data+i);
            sum[i]=data[i]+sum[i-1];
        }
        for(i=1,ans=0;i<=n;i++){
            for(j=i+1,k=0;j<=n;j++){
                if(data[j]>data[i])k++;
                l=data[i];
                r=data[j];
                if(l>r&&k>0||l<r&&j-i-k>0)continue;
                if(l>r)swap(l,r);
                if(j-i==r-l&&sum[j]-sum[i-1]==((l+r)*(r-l+1))/2)ans++;
            }
        }
        printf("%d\n",ans);
    }
}
