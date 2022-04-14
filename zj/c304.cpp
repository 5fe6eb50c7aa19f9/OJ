#include <iostream>
#include <cstdio>
using namespace std;
char data[100001];
int main(){
    long long n,i,ans;
    while(scanf("%lld",&n)==1){
        ans=0;
        i=n;
        while(i>0){
            ans=ans*10+i%10;
            i/=10;
        }
        printf("%lld\n",ans+n);
    }
}
