#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n,i,j;
    while(scanf("%d",&n)==1){
        j=1,i=1;
        while(j%n!=0){
            j%=n;
            j=j*10+1;
            i++;
        }
        printf("%d\n",i);
    }
}
