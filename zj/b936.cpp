#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    unsigned long long m,n;
    unsigned long long data[4];
    while(scanf("%llu %llu",&n,&m)==2){
        if(n<m){
            cout<<"0\n";
            continue;
        }
        data[0]=n-1;
        data[1]=0;
        data[2]=n;
        data[3]=1;
        while(data[0]!=0&&data[2]/2>=m){
            if(data[0]%2==0){
                data[1]=(data[1]<<1)+data[3];
            }else{
                data[3]=(data[3]<<1)+data[1];
            }
            data[0]=data[0]>>1;
            data[2]=data[0]+1;
        }
        printf("%llu\n",(data[0]>=m?data[1]+data[3]:data[3]));
    }
}
