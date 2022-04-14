#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int data[3500000];
int ans[1000001];
int main(){
    int n,i,j;
    for(i=1;i<3500000;i++){
        for(j=i<<1;j<3500000;j+=i){
            data[j]+=i;
        }
    }
    for(i=1;i<=1000000;i++){
        if(data[i]!=i&&data[data[i]]==i){
            ans[i]=data[i];
        }
    }
    while(scanf("%d",&n)==1&&n){
        if(data[n]==n){
            printf("=%d\n",n);
        }else if(ans[n]){
            printf("%d\n",ans[n]);
        }else{
            printf("0\n");
        }
    }
}
