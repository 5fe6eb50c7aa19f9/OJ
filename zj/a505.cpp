#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int sieve[(10000000>>5)+1];
int main(){
    int n;
    long long i,j;
    for(i=2;i<=10000000;i++){
        if(((sieve[i>>5]>>(i&31))&1)==0){
            for(j=i*i;j<=10000000;j+=i){
                sieve[j>>5]|=1<<(j&31);
            }
        }
    }
    scanf("%d",&n);
    while(n--){
        scanf("%lld",&i);
        j=sqrt(i);
        if(i!=1&&j*j==i&&(sieve[j>>5]>>(j&31))%2==0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}

