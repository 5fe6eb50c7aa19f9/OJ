#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int a,b,c,d,ans;
    while(scanf("%d %d %d %d",&a,&b,&c,&d)&&(a+b+c+d)){
        a=abs(a-c);
        b=abs(b-d);
        if(a==0&&b==0){
            printf("0\n");
        }else if(a==b||a==0||b==0){
            printf("1\n");
        }else{
            printf("2\n");
        }
    }
}
