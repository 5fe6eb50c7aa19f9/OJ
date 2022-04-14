#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n,k,i,j;
    while(scanf("%d %d",&n,&k)==2){
        for(i=2,j=0;i<=n;i++){
            j=(j+k)%i;
        }
        printf("%d\n",j+1);
    }
}
