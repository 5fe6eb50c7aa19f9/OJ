#include <iostream>
#include <cstdio>
using namespace std;
int seive[70000];
long long prime[10000];
int main(){
    long long i,j,k=0,n,ans;
    prime[k++]=2;
    for(i=3;i<70000;i+=2){
        if((seive[i>>5]>>(i&31))%2==0){
            prime[k++]=i;
            for(j=i*i;j<70000;j+=i){
                seive[j>>5]|=1<<(j&31);
            }
        }
    }
    while(scanf("%lld",&n)==1&&n){
        ans=1;
        for(i=0;prime[i]*prime[i]<=n;i++){
            if(n%prime[i]==0){
                j=0;
                while(n%prime[i]==0){
                    n/=prime[i];
                    j++;
                }
                ans*=j+1;
            }
        }
        if(n!=1){
            ans*=2;
        }
        if(ans%2){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
}
