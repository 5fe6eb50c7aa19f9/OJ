#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define abs(x) (x<0?x*-1:x)
#define pi 3.14159265358979323846
int main(){
    long double y;
    while(scanf("%Lf",&y)==1){
        if(abs(y)>1){
            printf("FAIL!\n");
            continue;
        }
        y=asin(y);
        if(abs(y)>1){
            printf("FAIL!\n");
            continue;
        }
        y=acos(y);
        y=y*180/pi;
        printf("%.2Lf\n",y);
    }
}
