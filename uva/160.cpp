#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

bool sieve[200];
int prime[100];
int cnt[100];
int num;
int main(){
    int i,j,k=1,n;
    prime[0]=2;
    for(i=3;i<200;i+=2){
        if(!sieve[i]){
            prime[k++]=i;
            for(j=i*i;j<200;j+=i){
                sieve[j]=1;
            }
        }
    }
    while(scanf("%d",&n)&&n){
        printf("%3d! =",n);
        for(i=0;i<100;i++)cnt[i]=0;
        num=0;
        for(i=2;i<=n;i++){
            for(j=i,k=0;j!=1;k++){
                if(j%prime[k]==0){
                    while(j%prime[k]==0){
                        j/=prime[k];
                        cnt[k]++;
                    }
                    num=max(num,k);
                }
            }
        }
        for(i=0;i<=num;i++){
            if(i&&i%15==0)printf("\n      ");
            printf("%3d",cnt[i]);
        }
        printf("\n");
    }
}
