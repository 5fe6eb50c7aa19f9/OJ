#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool dp[1000001];
int main(){
    int i,j,k;
    for(i=1;i<=1000000;i++){
        if(!dp[i]){
            printf("%d\n",i);
            for(j=i;j<=1000000&&!dp[j];j=k){
                dp[j]=1;
                k=j;
                while(j>0){
                    k+=j%10;
                    j/=10;
                }
            }
        }
    }
}
