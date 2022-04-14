#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)==2){
        if(m==1){
            printf("%d\n",n-1);
            continue;
        }
        if(n%m==1)n--;
        printf("%d\n",n%m==0?n/m:n/m+1);
    }
}
