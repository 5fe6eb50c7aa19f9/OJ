#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define abs(x) ((x)<0?(x)*-1:(x))
int main(){
    int data[9],head,i;
    while(scanf("%d",data)==1){
        head=1;
        for(i=1;i<9;i++)scanf("%d",data+i);
        for(i=0;i<9;i++){
            if(data[i]){
                if(head){
                    if(data[i]<0)printf("-");
                    if(abs(data[i])!=1||i==8)printf("%d",abs(data[i]));
                    head=0;
                }else{
                    printf(" %c ",data[i]<0?'-':'+');
                    if(abs(data[i])!=1||i==8)printf("%d",abs(data[i]));
                }
                if(i!=8){
                    printf("x");
                    if(i<7){
                        printf("^%d",8-i);
                    }
                }
            }
        }
        if(head){
            printf("0");
        }
        printf("\n");
    }
}
