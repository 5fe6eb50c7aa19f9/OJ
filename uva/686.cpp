#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
unsigned int seive[(50000>>5)+1];
int prime[10000],num;
int main(){
    int n,i,j,ans;
    prime[num++]=2;
    for(i=3;i<40000;i+=2){
        if((seive[i>>5]>>(i&31))%2==0){
            prime[num++]=i;
            for(j=i*i;j<40000;j+=i){
                seive[j>>5]|=1<<(j&31);
            }
        }
    }
    while(scanf("%d",&n)&&n){
        ans=0;
        for(i=0;prime[i]*2<=n;i++){
            j=n-prime[i];
            if(j==2||(j%2&&(seive[j>>5]>>(j&31))%2==0))ans++;
        }
        printf("%d\n",ans);
    }
}
