#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define ll long long
ll Mul(ll a,ll b,ll m){
    ll ret=0;
    while(b>0){
        if(b&1){
            ret=(ret+a)%m;
        }
        a=(a+a)%m;
        b>>=1;
    }
    return ret;
}
ll Pow(ll a,ll n,ll m){
    ll ret=1;
    while(n>0){
        if(n&1){
            ret=Mul(ret,a,m);
        }
        a=Mul(a,a,m);
        n>>=1;
    }
    return ret;
}
bool isPrime(ll n){
    if(n==2||n==3||n==5||n==7)return 1;
    if(n%2==0||n%3==0||n%5==0||n%7==0)return 0;
    if(Pow(420,n-1,n)!=1)return 0;
    return 1;
}
int sieve[100000];
ll prime[10000];
int main(){
    ll i,j,k=0,n,ans,flag;
    prime[k++]=2;
    for(i=3;i<100000;i+=2){
        if((sieve[i>>5]>>(i&31))%2==0){
            prime[k++]=i;
            for(j=i*i;j<100000;j+=i){
                sieve[j>>5]|=1<<(j&31);
            }
        }
    }
    while(scanf("%lld",&n)==1){
        if(n==0||n==1){
            printf("%d\n",1+(n==1));
            continue;
        }
        n*=2;
        k=sqrt(n);
        if(k*(k+1)==n){
            flag=1;
        }else{
            flag=0;
        }
        while(n%2==0)n>>=1;
        if(n==1){
            printf("1\n");
            continue;
        }
        ans=1;
        for(i=0;prime[i]*prime[i]*prime[i]<=n||prime[i]<=420;i++){
            if(n%prime[i]==0){
                j=0;
                do{
                    j++;
                    n/=prime[i];
                }while(n%prime[i]==0);
                ans*=j+1;
            }
        }
        if(n!=1){
            k=sqrt(n);
            if(k*k==n){
                ans*=3;
            }else if(isPrime(n)){
                ans*=2;
            }else{
                ans*=4;
            }
        }
        printf("%lld\n",ans+flag);
    }
}
