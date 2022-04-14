#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long n=0;
    while(scanf("%lld",&n)==1&&n>=0){
        printf("%lld\n",1+(1+n)*n/2);
    }
}
