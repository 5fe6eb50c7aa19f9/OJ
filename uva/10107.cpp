#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int data[10000];
int main() {
    int n=0,k,i;
    while(scanf("%d",&k)==1){
        data[n++]=k;
        for(i=n-1;i>0;i--){
            if(data[i-1]>data[i]){
                swap(data[i-1],data[i]);
            }
        }
        if(n&1){
            printf("%d\n",data[n/2]);
        }else{
            printf("%d\n",(data[n/2-1]+data[n/2])/2);
        }
    }
}
