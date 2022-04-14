#include <cstdio>
#include <cstdlib>
unsigned long long pow(unsigned long long a,unsigned long long n,unsigned long long m){
    unsigned long long k=1;
    while(n>0){
        if(n&1){
            k*=a;
            k%=m;
        }
        n>>=1;
        a=a*a%m;
    }
    return k;
}
bool isPrime(unsigned long long n){
    if(n==1)return 0;
    if(n==2||n==3||n==5)return 1;
    if(n%2==0||n%3==0||n%5==0)return 0;
    unsigned long long a;
    for(int i=0;i<2;i++){
        a=rand();
        a=a%(n-2)+2;
        if(pow(a,n-1,n)!=1)return 0;
    }
    return 1;
}
int main(){
    int n;
    while(scanf("%d",&n)&&n){
        printf("%d\n",!isPrime(n));
    }
}
