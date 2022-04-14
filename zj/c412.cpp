#include <cstdio>
#include <iostream>
using namespace std;

char data[1000001];
int main(){
    int t,i,j,k,ans;
    scanf("%d%*c",&t);
    while(t--){
        i=j=ans=0;
        while(scanf("%1000000[^\n]",data)){
            for(k=0;k<1000000&&data[k];k++){
                if(data[k]=='O'){
                    j++;
                    ans=(ans+i)%1000000007;
                }else if(data[k]=='w'){
                    i=(i+j)%1000000007;
                }
            }
            if(k!=1000000)break;
        }
        scanf("%*c");
        printf("%d\n",ans);
    }
}
