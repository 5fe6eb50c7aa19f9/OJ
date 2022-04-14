#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int r,c,ans;
    while(scanf("%d %d",&r,&c)==2){
        printf("%d\n",min(r-1+r*(c-1),c-1+c*(r-1)));
    }
}
