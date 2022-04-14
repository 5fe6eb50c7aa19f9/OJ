#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int sieve[1100000>>5];
long long prime[100000];
long long factor[100];
int num;
long long n,sum;
void sol(int i,long long combi){
    if(i==num){
        sum+=combi;
        return;
    }
    long long j=1;
    while(n%(combi*j)==0){
        sol(i+1,combi*j);
        j*=factor[i];
    }
}
int main(){
    long long t,i,j,k=0;
    prime[k++]=2;
    for(i=3;i<1100000;i+=2){
        if((sieve[i>>5]>>(i&31))%2==0){
            prime[k++]=i;
            for(j=i*i;j<1100000;j+=i){
                sieve[j>>5]|=1<<(j&31);
            }
        }
    }
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        num=0;
        for(i=0,k=n;prime[i]*prime[i]<=k;i++){
            if(k%prime[i]==0){
                while(k%prime[i]==0)k/=prime[i];
                factor[num++]=prime[i];
            }
        }
        if(k!=1)factor[num++]=k;
        sum=0;
        sol(0,1);
        sum-=n;
        if(sum>n){
            printf("abundant\n");
        }else if(sum==n){
            printf("perfect\n");
        }else{
            printf("deficient\n");
        }
    }
}
