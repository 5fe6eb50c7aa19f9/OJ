#include <iostream>
#include <cstdio>
using namespace std;
char data[100001];
int main(){
    int n,i;
    while(scanf("%d",&n)==1){
        scanf("%s",data);
        for(i=0;data[i];i++){
            printf("%c",data[i]^32);
        }
        printf("\n");
    }
}
