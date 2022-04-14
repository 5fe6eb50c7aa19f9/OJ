#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long data[3];
    int i,j,t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        for(i=0;i<3;i++)scanf("%lld",data+i);
        sort(data,data+3);
        if(data[0]+data[1]<=data[2]){
            printf("Case %d: Invalid",t);
        }else if(data[0]==data[1]&&data[1]==data[2]){
            printf("Case %d: Equilateral",t);
        }else if(data[0]!=data[1]&&data[1]!=data[2]&&data[0]!=data[2]){
            printf("Case %d: Scalene",t);
        }else{
            printf("Case %d: Isosceles",t);
        }
        printf("\n");
    }
}
