#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long n,i,j,ans;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%lld",&n)&&n){
        ans=n>1?1:0;
        for(i=2;i*i<=n;i++){
            if(n%i==0){
                ans+=i;
                if(i*i!=n)ans+=n/i;
            }
        }
        printf("%5lld  ",n);
        if(ans>n){
            printf("ABUNDANT\n");
        }else if(ans<n){
            printf("DEFICIENT\n");
        }else{
            printf("PERFECT\n");
        }
    }
    printf("END OF OUTPUT\n");
}
