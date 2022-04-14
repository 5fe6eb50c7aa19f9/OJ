#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int n,a,b,c;
    double ans;
    while(scanf("%d",&n)==1&&n){
        while(n--){
            scanf("%d %d %d",&a,&b,&c);
            ans=(double)(a*a+c*c+b*b)/3;
            printf("%.1lf\n",ans);
        }
    }
}
