#include <cstdio>
#include <iostream>
using namespace std;
long long m;
long long a[2][2];
long long b[2][2];
long long tmp[2][2];
int main(){
    int n,i,j,k;
    while(scanf("%d %d",&n,&m)==2){
        if(n==0){
            printf("0\n");
            continue;
        }
        m=1<<m;
        a[0][0]=a[0][1]=a[1][0]=1;
        a[1][1]=0;
        b[0][0]=b[1][1]=1;
        b[0][1]=b[1][0]=0;
        n--;
        while(n){
            if(n&1){
                for(i=0;i<2;i++){
                    for(j=0;j<2;j++){
                        tmp[i][j]=0;
                        for(k=0;k<2;k++){
                            tmp[i][j]+=a[i][k]*b[k][j];
                        }
                        tmp[i][j]%=m;
                    }
                }
                for(i=0;i<2;i++){
                    for(j=0;j<2;j++){
                        b[i][j]=tmp[i][j];
                    }
                }
            }
            for(i=0;i<2;i++){
                for(j=0;j<2;j++){
                    tmp[i][j]=0;
                    for(k=0;k<2;k++){
                        tmp[i][j]+=a[i][k]*a[k][j];
                    }
                    tmp[i][j]%=m;
                }
            }
            for(i=0;i<2;i++){
                for(j=0;j<2;j++){
                    a[i][j]=tmp[i][j];
                }
            }
            n>>=1;
        }
        printf("%lld\n",b[0][0]);
    }
}
