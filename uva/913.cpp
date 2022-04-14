#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    unsigned long long n,i,j;
    while(scanf("%llu",&n)==1){
        i=(n+1)/2;
        j=(1+n)*i/2;
        i=1+(j-1)*2;
        printf("%llu\n",i*3-6);
    }
}
