#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const long long lim=3000000000;
long long gcd(long long a,long long b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
long long mult(long long a,long long b,long long m){
    if(m<=lim)return a*b%m;
    long long ans=0;
    while(b>0){
        if(b&1){
            ans=(ans+a)%m;
        }
        a=(a*2)%m;
        b>>=1;
    }
    return ans;
}
long long Pow(long long a,long long b,long long m){
    long long ans=1;
    while(b>0){
        if(b&1){
            if(m<=lim){
                ans=ans*a%m;
            }else{
                ans=mult(ans,a,m);
            }
        }
        if(m<=lim){
            a=a*a%m;
        }else{
            a=mult(a,a,m);
        }
        b>>=1;
    }
    return ans;
}
bool isPrime(long long m){
    if(m==2||m==3||m==5||m==7)return 1;
    if(m%2==0||m%3==0||m%5==0||m%7==0)return 0;
    if(Pow(2,m-1,m)!=1)return 0;
    return 1;
}
long long pollard_rho(long long n,long long c){
    long long x=2,y=2,i=1,k=2,d;
    while(1){
        x=mult(x,x,n)+c;
        if(x>=n)x-=n;
        d=gcd(abs(x-y),n);
        if(d>1)return d;
        if(x==y)return n;
        if(++i==k){
            y=x;
            k<<=1;
        }
    }
}
int sieve[1000050>>5];
long long prime[78502];
long long factor[70][2];
int num;
int main(){
    int t;
    long long n,i,j,k=0;
    prime[k++]=2;
    for(i=3;i<1000050;i+=2){
        if(((sieve[i>>5]>>(i&31))&1)==0){
            prime[k++]=i;
            for(j=i*i;j<1000050;j+=i){
                sieve[j>>5]|=1<<(j&31);
            }
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        printf("%lld =",n);
        num=0;
        for(i=0;prime[i]*prime[i]*prime[i]<=n;i++){
            if(n%prime[i]==0){
                factor[num][0]=prime[i];
                factor[num][1]=0;
                while(n%prime[i]==0){
                    n/=prime[i];
                    factor[num][1]++;
                }
                num++;
            }
        }
        if(n!=1){
            if(isPrime(n)){
                factor[num][0]=n;
                factor[num][1]=1;
                num++;
            }else{
                k=sqrt(n);
                if(k*k==n){
                    factor[num][0]=k;
                    factor[num][1]=2;
                    num++;
                }else{
                    for(i=2;;i++){
                        j=pollard_rho(n,i);
                        if(j!=n){
                            factor[num][0]=min(j,n/j);
                            factor[num+1][0]=max(j,n/j);
                            factor[num][1]=factor[num+1][1]=1;
                            num+=2;
                            break;
                        }
                    }
                }
            }
        }
        for(i=0;i<num;i++){
            printf(" %lld",factor[i][0]);
            if(factor[i][1]>1){
                printf("^%lld",factor[i][1]);
            }
            if(i+1<num){
                printf(" *");
            }
        }
        printf("\n");
    }
}
