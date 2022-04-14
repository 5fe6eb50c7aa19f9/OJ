#include <cstdio>
#include <iostream>
using namespace std;
#define lim 1000000000000000000//10^18
unsigned long long f[20001][334];

int main(){
    int i,j,n,flag;
    f[1][0]=1;
    for(i=2;i<20001;i++){
        for(j=0;j<334;j++){
            f[i][j]+=f[i-1][j]+f[i-2][j];
            if(f[i][j]>=lim){
                f[i][j]-=lim;
                f[i][j+1]++;
            }
        }
    }
    while(scanf("%d",&n)==1){
        if(n==0){
            printf("0\n");
            continue;
        }
        flag=0;
        for(i=333;i>=0;i--){
            if(flag==0&&f[n][i]!=0){
                printf("%llu",f[n][i]);
                flag=1;
                continue;
            }
            if(flag==1){
                printf("%0.18llu",f[n][i]);
            }
        }
        printf("\n");
    }
}
