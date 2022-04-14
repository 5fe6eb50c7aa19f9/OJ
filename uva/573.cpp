#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int H,U,D,F,i,j;
    double now,delta;
    while(scanf("%d %d %d %d",&H,&U,&D,&F)&&H){
        now=0;
        for(i=0;;i++){
            delta=U*(100-i*F);
            delta/=100.0;
            if(delta>0.0)now+=delta;
            if(now>H){
                printf("success on day %d\n",i+1);
                break;
            }
            now-=D;
            if(now<0){
                printf("failure on day %d\n",i+1);
                break;
            }
        }
    }
}
