#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long gcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        return a;
    }else{
        long long r=gcd(b,a%b,x,y);
        if(a%b==1){
            x=1,y=(a/b)*-1;
        }else{
            long long tmp=x;
            x=y;
            y=tmp-(a/b)*y;
            return r;
        }
        return r;
    }
}

int main(){
    long long i,j,n,m,x,y,ans;
    while(scanf("%lld %lld",&n,&m)==2){
        ans=gcd(n,m,x,y);
        if(m!=1&&ans==1){
            x=((x*x)%m)*n%m;
            printf("%lld\n",x);
        }else{
            printf("No Inverse\n");
        }
    }
}
