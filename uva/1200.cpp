#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    string data;
    int t,i,j,ax,b;
    bool sign,eq,x;
    scanf("%d",&t);
    getline(cin,data);//for '\n' from last line
    while(t--){
        getline(cin,data);
        data+="=";
        ax=b=sign=eq=x=0;
        for(i=0,j=0;i<data.size();i++){
            if(data[i]=='+'){
                if(sign)j*=-1;
                if(eq)j*=-1;
                if(x)ax+=j;
                else b+=j;
                j=sign=x=0;
            }else if(data[i]=='-'){
                if(sign)j*=-1;
                if(eq)j*=-1;
                if(x)ax+=j;
                else b+=j;
                j=x=0;
                sign=1;
            }else if(data[i]=='='){
                if(sign)j*=-1;
                if(eq)j*=-1;
                if(x)ax+=j;
                else b+=j;
                j=x=sign=0;
                eq=1;
            }else if(data[i]=='x'){
                x=1;
                if(j==0)j++;
            }else{
                j=j*10+data[i]-'0';
            }
        }
        if(ax==0&&b==0){
            printf("IDENTITY\n");
        }else if(ax==0&&b!=0){
            printf("IMPOSSIBLE\n");
        }else{
            if(b<0&&ax>=0||ax<0&&b>=0){
                printf("%d\n",b/ax*-1);
            }else{
                printf("%d\n",b%ax==0?b/ax*-1:b/ax*-1-1);
            }
        }
    }
}
