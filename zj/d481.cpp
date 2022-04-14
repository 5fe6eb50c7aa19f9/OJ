#include <cstdio>
#include <iostream>
using namespace std;
long long a[101][101];
long long b[101][101];
long long tmp;
int main(){
    int ar,ac,br,bc,i,j,k;
    while(scanf("%d %d %d %d",&ar,&ac,&br,&bc)==4){
        if(ac!=br){
            printf("Error\n");
            continue;
        }
        for(i=1;i<=ar;i++){
            for(j=1;j<=ac;j++){
                scanf("%lld",a[i]+j);
            }
        }
        for(i=1;i<=br;i++){
            for(j=1;j<=bc;j++){
                scanf("%lld",b[i]+j);
            }
        }
        for(i=1;i<=ar;i++){
            for(j=1;j<=bc;j++){
                tmp=0;
                for(k=1;k<=ac;k++){
                    tmp+=a[i][k]*b[k][j];
                }
                printf("%lld ",tmp);
            }
            printf("\n");
        }
    }
}
