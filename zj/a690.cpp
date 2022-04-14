#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n,i;
    while(scanf("%d",&n)==1){
        printf("[");
        for(i=n;i>=1;i--){
            if(i<n)printf(" ");
            printf("%d",i);
        }
        for(i=2;i<=n;i++)printf(" %d",i);
        printf("]\n");
    }
}
