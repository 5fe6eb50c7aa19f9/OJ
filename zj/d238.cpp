#include <cstdio>
#include <iostream>
using namespace std;

char ans[1000];
int main(){
    ans[0]=1;
    int i,j,k=0;
    for(i=0;i<1000;i++){
        for(j=0;j<=k;j++){
            ans[j]<<=1;
        }
        for(j=0;j<=k;j++){
            ans[j+1]+=ans[j]/10;
            ans[j]%=10;
        }
        if(ans[k+1])k++;
    }
    i=0;
    while(k>=0){
        i+=ans[k--];
    }
    printf("%d",i);
}
