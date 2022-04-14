#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T,t,a,b;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d %d",&a,&b);
        if(a%2==0)a++;
        if(b%2==0)b--;
        if(a>b){
            printf("Case %d: 0\n",t);
            continue;
        }
        printf("Case %d: %d\n",t,((a+b)/2)*((b+2-a)/2));
    }
}
