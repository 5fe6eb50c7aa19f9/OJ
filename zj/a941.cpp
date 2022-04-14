#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long data[2000000];
int main(){
    int t,n,i;
    long long ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lld",data+i);
        }
        sort(data,data+n);
        ans=0;
        for(i=0;i<n;i++){
            ans+=abs(data[n/2]-data[i]);
        }
        printf("%lld %lld\n",ans,n%2==0?data[n/2-1]:data[n/2]);
    }
}
