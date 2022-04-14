#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

char str[1002];
int main(){
    int n,pos;
    while(scanf("%d",&n)&&n>=0){
        if(!n){
            printf("0\n");
            continue;
        }
        pos=1000;
        while(n>0){
            str[pos--]=n%8+'0';
            n/=8;
        }
        printf("%s\n",str+pos+1);
    }
    printf("-1\n");
}
