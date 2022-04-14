#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int t,i;
    int data[4];
    scanf("%d",&t);
    while(t--){
        for(i=0;i<4;i++)scanf("%d",data+i);
        sort(data,data+4);
        if(data[0]==0){
            printf("banana\n");
        }else if(data[0]==data[3]){
            printf("square\n");
        }else if(data[0]==data[1]&&data[2]==data[3]){
            printf("rectangle\n");
        }else if(data[0]+data[1]+data[2]>data[3]){
            printf("quadrangle\n");
        }else{
            printf("banana\n");
        }
    }
}
