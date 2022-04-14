#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
string a;
int now;
int go(char op){
    int tmp1=0,tmp2=0;
    if(!(a[now]>='0'&&a[now]<='9')){
        now-=2;
        tmp1=go(a[now+2]);
    }else{
        for(int i=1;now>=0&&a[now]!=' ';i*=10,now--){
            tmp1=tmp1+(a[now]-'0')*i;
        }
    }
    now--;
    if(!(a[now]>='0'&&a[now]<='9')){
        now-=2;
        tmp2=go(a[now+2]);
    }else{
        for(int i=1;now>=0&&a[now]!=' ';i*=10,now--){
            tmp2=tmp2+(a[now]-'0')*i;
        }
    }
    switch(op){
        case '+':
            return tmp2+tmp1;
            break;
        case '-':
            return tmp2-tmp1;
            break;
        case '*':
            return tmp2*tmp1;
            break;
        case '/':
            return tmp2/tmp1;
            break;
        case '%':
            return tmp2%tmp1;
            break;
    }
}
int main(){
    while(getline(cin,a)){
        int flag=0;
        for(int i=0;i<a.size();i++)if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')flag=i;//to prevent from RE
        now=flag-2;
        cout<<go(a[flag])<<endl;
    }
}
