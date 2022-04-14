#include <cstdio>
#include <iostream>
using namespace std;
#define abs(x) ((x)<0?(x)*-1:(x))
char data[150000];
int main(){
    int i,y,ans;
    while(scanf("%s",data)==1){
        y=ans=0;
        for(i=0;data[i];i++){
            if(data[i]=='y'){
                ans+=abs(i-y);
                y+=3;
            }
        }
        printf("%d\n",ans);
    }
}
