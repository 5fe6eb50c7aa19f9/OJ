#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int main(){
    int n,i,j,ans;
    while(scanf("%d",&n)==1){
        j=sqrt(n);
        n-=j*j;
        ans=j+j-1+n/j;
        n%=j;
        if(n!=0)ans++;
        printf("%d\n",ans);
    }
}
