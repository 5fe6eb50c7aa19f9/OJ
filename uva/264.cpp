#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,i,tmp;
    while(scanf("%d",&n)==1){
        for(i=2;;i++){
            if(i*(i-1)/2>=n)break;
        }
        i--;
        tmp=n-i*(i-1)/2;
        i++;
        printf("TERM %d IS ",n);
        if(i&1){
            printf("%d/%d\n",tmp,i-tmp);
        }else{
            printf("%d/%d\n",i-tmp,tmp);
        }
    }
}
