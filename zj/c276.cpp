#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
    int i,j,n,a,b;
    char ans[5];
    char test[5];
    scanf("%s",ans);
    scanf("%d",&n);
    while(n--){
        scanf("%s",test);
        a=b=0;
        for(i=0;i<4;i++){
            if(test[i]==ans[i])a++;
            for(j=0;j<4;j++){
                if(test[i]==ans[j])b++;
            }
        }
        b-=a;
        printf("%dA%dB\n",a,b);
    }
}
