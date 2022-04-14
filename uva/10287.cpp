#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    long double s,three=3.0,seven=7.0;
    while(scanf("%Lf",&s)==1){
        printf("%.10Lf %.10Lf %.10Lf %.10Lf\n",s*pow(three/4.0,0.5),s*3/(3+pow(three*4.0,0.5)),s*pow(three/16.0,0.5),s*(6.0*pow(seven,0.5)-7.0*pow(three,0.5))/10.0);
    }
}
