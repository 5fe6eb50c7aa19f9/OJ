#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int A,B,C;
    double a,b,c,x;
    while(scanf("%d %d %d",&A,&B,&C)==3&&A+B+C){
        if(C<B)swap(C,B);
        if(C<A)swap(C,A);
        a=A,b=B,c=C;
        if(A*A+B*B-C*C<=-1*A*B){
            printf("%0.2lf\n",a+b);
        }else{
            x=(a*a+c*c-b*b)/(2*c);
            printf("%.2lf\n",sqrt(pow((x-0.5*c),2.0)+pow(sqrt(a*a-x*x)+sqrt(3.0)*c/2.0,2.0)));
        }
    }
}
