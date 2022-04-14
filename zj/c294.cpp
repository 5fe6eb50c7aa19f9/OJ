#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a>c)swap(a,c);
    if(b>c)swap(b,c);
    if(a>b)swap(a,b);
    printf("%d %d %d\n",a,b,c);
    if(a+b<=c){
        printf("No\n");
    }else{
        if(a*a+b*b<c*c){
            printf("Obtuse\n");
        }else if(a*a+b*b>c*c){
            printf("Acute\n");
        }else{
            printf("Right\n");
        }
    }
}
