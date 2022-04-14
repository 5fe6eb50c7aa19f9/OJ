#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long c[4]={10000000,100000,1000,100};
void go(long long data){
    if(data>=c[0]){
        go(data/c[0]);
        printf(" kuti");
        data%=c[0];
    }
    for(int i=1;i<4;i++){
        if(data/c[i]>0){
            printf(" %lld",data/c[i]);
            data%=c[i];
            if(i==1){
                printf(" lakh");
            }else if(i==2){
                printf(" hajar");
            }else if(i==3){
                printf(" shata");
            }
        }
    }
    if(data){
        printf(" %lld",data);
    }
}
int main(){
    int i,t=0;
    long long data;
    while(scanf("%lld",&data)==1){
        t++;
        if(data==0){
            printf("%4d. 0\n",t);
            continue;
        }
        printf("%4d.",t);
        go(data);
        printf("\n");
    }
}
