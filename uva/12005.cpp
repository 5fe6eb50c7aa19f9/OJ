#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define Max 20000000
int prime[(Max>>5)+1]={0};//bit prime sieve
long long pr[1300000]={0};//declare in main function will error
long long p=0;

int main(){
    for(long long i=3;i<Max;i+=2){
        if(((prime[i>>5]>>(i&31))&1)==0){
            for(long long j=i*i;j<Max;j+=i)prime[j>>5]|=(1<<(j&31));
            pr[p++]=i;
        }
    }
    long long c;
    while(scanf("%lld",&c)==1&&c){
        printf("%lld ",c);
        c=(c<<2)-3;
        long long sum=1;
        for(long long i=0,tmp2;pr[i]*pr[i]<=c&&c!=1&&i<p;i++){//use sqrt(c)>=pr[i] will TLE
            tmp2=1;
            while(c%pr[i]==0){
                c/=pr[i];
                tmp2++;
            }
            sum*=tmp2;
        }
        if(c!=1)sum=sum<<1;
        printf("%lld\n",sum);
    }
}
