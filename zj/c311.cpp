#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

char data[100005];
int main(){
    int i,j;
    while(scanf("%s",&data)==1){
        for(i=0,j=0;data[i];i++){
            j=j*10+data[i]-'0';
            j%=91;
        }
        printf("%d\n",j);
    }
}
