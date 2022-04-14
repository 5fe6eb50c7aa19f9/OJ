#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long A[2][4];
unsigned long long ans[2][4];
void mult(unsigned long long* a,unsigned long long* b,unsigned long long* stored){
    int i,j;
    for(i=0;i<4;i++)stored[i]=0;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            stored[i+j]+=a[i]*b[j];
            if(stored[i+j]>=(1<<30)){
                stored[i+j+1]+=(stored[i+j]>>30);
                stored[i+j]&=0x3fffffff;
            }
        }
    }
}
void mod(unsigned long long* a,unsigned long long m,unsigned long long* stored){
    int i;
    for(i=0;i<4;i++)stored[i]=0;
    a[0]+=(a[1]<<30);
    a[1]=0;
    a[2]+=(a[3]<<30);
    a[3]=0;
    if(a[2]==0){
        a[0]%=m;
    }else{
        for(i=59;i>=0;i--){
            a[2]<<=1,a[2]+=((a[0]>>i)&1);
            if(a[2]>=m){
                a[2]%=m;
            }
        }
        a[0]=a[2];
    }
    if(a[0]>=(1<<30)){
        a[1]=a[0]>>30;
        a[0]&=0x3fffffff;
    }
    stored[0]=a[0],stored[1]=a[1];
}
unsigned long long Pow(unsigned long long a,unsigned long long n,unsigned long long m){
    int i;
    for(i=0;i<4;i++)A[0][i]=0,A[1][i]=0;
    A[0][0]=a;
    for(i=0;i<4;i++)ans[0][i]=0,ans[1][i]=0;
    ans[0][0]=1;
    while(n>0){
        if(n&1){
            mult(ans[0],A[0],ans[1]);
            mod(ans[1],m,ans[0]);
        }
        mult(A[0],A[0],A[1]);
        mod(A[1],m,A[0]);
        n>>=1;
    }
    return ans[0][0];
}
bool isPrime(unsigned long long n){
    if(n==2||n==3)return 1;
    if((n&1)==0)return 0;
    unsigned int a,i;
    for(i=0;i<3;i++){
        a=rand();
        a=a%(n-2)+2;
        if(Pow(a,n-1,n)!=1)return 0;//Fermat's little theory
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
        for(i=0;i<p&&prime[i]*prime[i]*prime[i]<=N;i++){
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
            if(isPrime(N)){
                ans<<=1;
            }else{
                tmp=sqrt(N);
                if(tmp*tmp==N){
                    ans*=3;
                }else{
                    ans<<=2;
                }
            }
        }
        printf("%llu\n",ans-1);
    }
}
