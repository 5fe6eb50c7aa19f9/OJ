#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    double n,p;
    while(scanf("%lf %lf",&n,&p)==2){
        printf("%0.f\n",pow(p,1.0/n));
    }
}
