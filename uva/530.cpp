#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int gcd(int a,int b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
int fac[1000000];
int main(){
    int n,m,i,j,k,num,tmp,ans;
    while(scanf("%d %d",&n,&m)&&n+m){
        if(m==0){
            printf("1\n");
            continue;
        }
        for(i=max(n-m,m)+1,num=0;i<=n;i++){
            fac[num++]=i;
        }
        for(i=1;i<=min(n-m,m);i++){
            for(j=0,k=i;k!=1;j++){
                tmp=gcd(fac[j],k);
                k/=tmp;
                fac[j]/=tmp;
            }
        }
        for(i=0,ans=1;i<num;i++){
            ans*=fac[i];
        }
        printf("%d\n",ans);
    }
}
