#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char data[100];
int main() {
    int i,ans;
    while(scanf("%s",data)==1){
        if(data[0]=='-')break;
        if(data[0]=='0'&&data[1]=='x'){
            for(i=2,ans=0;data[i];i++){
                ans=ans*16+data[i];
                if(data[i]>='0'&&data[i]<='9'){
                    ans-='0';
                }else{
                    ans-='A'-10;
                }
            }
            printf("%d\n",ans);
        }else{
            for(i=0,ans=0;data[i];i++){
                ans=ans*10+data[i]-'0';
            }
            printf("0x%X\n",ans);
        }
    }
}
