#include <iostream>
#include <cstdio>
using namespace std ;

int sol(int n,int mode){
    if(n==1)return 1;
    if(mode==0){
        if(n&1){
            return sol(n/2,1)*2;
        }else{
            return sol(n/2,0)*2;
        }
    }else{
        if(n&1){
            return (sol(n/2,1)+1)*2-1;
        }else{
            return sol(n/2,1)*2-1;
        }
    }
}
int main(){
    int n;
    while(scanf("%d",&n)==1&&n){
        printf("%d\n",sol(n,0));
    }
}


