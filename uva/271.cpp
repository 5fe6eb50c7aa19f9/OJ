#include <cstdio>
#include <algorithm>
using namespace std;

char data[257];
bool sol(int top){
    int tmp=0;
    while(top!=-1){
        if(data[top]>='p'&&data[top]<='z'){
            tmp++;
        }else if(data[top]=='N'){
            if(!tmp)return 0;
        }else if(data[top]=='C'||data[top]=='D'||data[top]=='E'||data[top]=='I'){
            if(tmp<2)return 0;
            tmp--;
        }else{
            return 0;
        }
        top--;
    }
    if(tmp>1)return 0;
    return 1;
}
int main(){
    int i,j;
    while(scanf("%s",data)==1){
        for(i=0;data[i];i++);
        if(sol(i-1)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}
