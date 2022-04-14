#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n,i;
    while(scanf("%d",&n)==1){
        for(i=1;i<=n;i++){
            if(i%3==0||i%10==3){
                printf("YA\n");
            }else{
                printf("%d\n",i);
            }
        }
    }
}
