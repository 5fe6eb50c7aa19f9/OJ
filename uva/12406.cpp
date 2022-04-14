#include <iostream>
#include <cstdio>
using namespace std;
long long a,b;
void go(long long p,long long q,long long n){
    if(p==0){
        if(n%q!=0)return;
        a=min(a,n);
        b=max(b,n);
        return;
    }
    go(p-1,q,n*10+1);
    go(p-1,q,n*10+2);
}
int main(){
    long long t,T,i,j,p,q;
    scanf("%lld",&T);
    for(t=1;t<=T;t++){
        scanf("%lld %lld",&p,&q);
        a=0x7fffffffffffffff;
        b=0x8000000000000000;
        go(p,1<<q,0);
        if(a==0x7fffffffffffffff&&b==0x8000000000000000){
            printf("Case %lld: impossible\n",t);
        }else if(a!=b){
            printf("Case %lld: %lld %lld\n",t,a,b);
        }else{
            printf("Case %lld: %lld\n",t,a);
        }
    }
}
