#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int sieve[1000];
int prime[1000];
int main(){
    long long n,c,i,j,k;
    prime[0]=1,prime[1]=2;
    k=2;
    for(i=3;i<1100;i+=2){
        if(((sieve[i>>5]>>(i&31))%2)==0){
            prime[k++]=i;
            for(j=i*i;j<1100;j+=i){
                sieve[j>>5]|=1<<(j&31);
            }
        }
    }
    while(scanf("%lld %lld",&n,&c)==2){
        i=0;
        while(prime[i]<=n)i++;
        if(i%2==0){
            j=i/2-c;
            k=i/2-1+c;
        }else{
            j=i/2+1-c;
            k=i/2-1+c;
        }
        i=0;
        printf("%lld %lld:",n,c);
        while(prime[i]<=n){
            if(i>=j&&i<=k){
                printf(" %d",prime[i]);
            }
            i++;
        }
        printf("\n\n");
    }
}
