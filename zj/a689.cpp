#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int x;
    while(scanf("%d",&x)==1){
        if(x>100){
            printf("Hey, DO NOT CHEAT.\n");
        }else if(x==100){
            printf("PERFECT >///<\n");
        }else if(x>=90){
            printf("Good Job!\n");
        }else if(x>=60){
            printf("Pass :)\n");
        }else{
            printf("Need +%d Q_Q...\n",60-x);
        }
    }
}
