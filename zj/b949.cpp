#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    while(scanf("%lld",&n)==1){
        if(n>1){
            printf("%lld%02lld\n",n*n/4,(n*n%4)*25);
        }else{
            printf("%lld\n",n*n*25);
        }
    }
}
