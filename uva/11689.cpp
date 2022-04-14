#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int t,T,n,i,j,k,ans;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d %d %d",&i,&j,&k);
        n=i+j;
        ans=0;
        while(n>=k){
            ans+=n/k;
            n=n/k+n%k;
        }
        printf("%d\n",ans);
    }
}
