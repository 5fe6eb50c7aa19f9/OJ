#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
bool sieve[1000001];
int prime[100000];
int main(){
    long long i,j,k=0;
    for(i=2;i<=1000000;i++){
        if(!sieve[i]){
            prime[k++]=i;
            for(j=i*i;j<=1000000;j+=i){
                sieve[j]=1;
            }
        }
    }
    int n;
    while(scanf("%d",&n)&&n){
        for(i=1;;i++){
            if(prime[i]*2>n){
                printf("Goldbach's conjecture is wrong.\n");
                break;
            }
            if(!sieve[n-prime[i]]){
                printf("%d = %d + %d\n",n,prime[i],n-prime[i]);
                break;
            }
        }
    }
}
