#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n,i,j,k;
    while(scanf("%d",&n)&&n){
        i=sqrt(n);
        if(i*i==n)i--;
        n-=i*i;
        if(n>=1&&n<=i){
            if(i%2==0)printf("%d %d\n",i+1,n);
            else printf("%d %d\n",n,i+1);
        }else{
            if(i%2==0)printf("%d %d\n",i+2-(n-i),i+1);
            else printf("%d %d\n",i+1,i+2-(n-i));
        }
    }
}
