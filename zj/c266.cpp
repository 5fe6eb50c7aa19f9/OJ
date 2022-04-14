#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int witness[]={2,17};
unsigned long long abmodm(unsigned long long a,unsigned long long b,unsigned long long m){
    unsigned long long tmp=a,ans=0;
    while(b>0){
        if(b&1)ans=(ans+tmp)%m;
        b>>=1;
        tmp=tmp*2%m;
    }
    return ans;
}
unsigned long long Pow(unsigned long long a,unsigned long long n,unsigned long long m){
    unsigned long long tmp=a,ans=1;
    while(n>0){
        if(n&1){
            if(m<0x7fffffff){
                ans=ans*tmp%m;
            }else{
                ans=abmodm(ans,tmp,m);
            }
        }
        n>>=1;
        if(m<0x7fffffff){
            tmp=tmp*tmp%m;
        }else{
            tmp=abmodm(tmp,tmp,m);
        }
    }
    return ans;
}
bool isPrime(unsigned long long n){
    if(n==2||n==3||n==5)return 1;
    if(n%2==0||n%3==0||n%5==0)return 0;
    for(int i=0;i<1;i++){
        if(Pow(witness[i],n-1,n)!=1)return 0;//Fermat's little theory
    }
    return 1;
}
int sieve[(1000050>>5)+1];
unsigned long long prime[78501];
int p;
int main(){
    unsigned long long N,i,j,tmp,ans;
    for(i=3;i<1000050;i+=2){
        if((sieve[i>>5]&(1<<(i&31)))==0){
            prime[p++]=i;
            for(j=i*i;j<1000050;j+=i){
                sieve[j>>5]|=1<<(j&31);
            }
        }
    }
    while(scanf("%llu",&N)&&N){
        while((N&1)==0)N>>=1;
        ans=1;
        for(i=0;prime[i]*prime[i]*prime[i]<=N;i++){
            if(N%prime[i]==0){
                tmp=1;
                do{
                    N/=prime[i];
                    tmp++;
                }while(N%prime[i]==0);
                ans*=tmp;
            }
        }
        if(N!=1){
            tmp=sqrt(N);
            if(tmp*tmp==N){
                ans*=3;
            }else{
                if(isPrime(N)){
                    ans<<=1;
                }else{
                    ans<<=2;
                }
            }
        }
        printf("%llu\n",ans-1);
    }
}
