#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long gcd(long long a,long long b){
    if(b==0)return a;
    return gcd(b,a%b);
}
long long data[15];
long long n,m,ans;
void brute(long long now,long long combi,long long lcm){
    if(now==m||lcm>n){
        if(combi&1){
            ans-=n/lcm;
        }else{
            ans+=n/lcm;
        }
        return;
    }
    brute(now+1,combi,lcm);
    brute(now+1,combi+1,lcm*data[now]/gcd(lcm,data[now]));
}
int main(){
    long long i,j;
    while(scanf("%lld %lld",&n,&m)==2){
        for(i=0;i<m;i++){
            scanf("%lld",data+i);
        }
        ans=0;
        brute(0,0,1);
        printf("%lld\n",ans);
    }
}
