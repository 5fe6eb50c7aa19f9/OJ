#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int ret[1001];
int main(){
    int t,n,i,j;
    for(i=2;i<=1000;i++){
        for(j=i+i;j<=1000;j+=i){
            ret[j]+=i;
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(ret[n]+1<n){
            printf("deficient\n");
        }else if(ret[n]+1==n){
            printf("perfect\n");
        }else{
            printf("abundant\n");
        }
    }
}
