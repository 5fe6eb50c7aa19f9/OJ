#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
    int i,n;
    char ans[52];
    ans[51]=0;
    while(scanf("%d",&n)==1&&n>=0){
        if(n==0){
            printf("0\n");
            continue;
        }
        i=50;
        while(n>0){
            ans[i--]='0'+n%3;
            n/=3;
        }
        printf("%s\n",ans+i+1);
    }
}
