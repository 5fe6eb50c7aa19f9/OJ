#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <stack>
using namespace std;
char arr[1000000];
int pos;
double X;
char graph[21][22];
double clc(stack<double> &v,stack<int> &op);
double sol();
void print();
void initialize();
int main(){
    int i,j;
    while(scanf("%[^\n]%*c",arr)==1){
        initialize();
        for(i=0;i<21;i++){
            X=(i-10);
            pos=5;
            j=(int)floor(sol());
            if(j>=-10&&j<=10){
                graph[10-j][i]='*';
            }
        }
        print();
    }
}
void initialize(){
    int i,j;
    for(i=0;i<21;i++){
        for(j=0;j<21;j++){
            graph[i][j]='.';
        }
    }
    for(i=0;i<21;i++){
        graph[i][10]='|';
    }
    for(j=0;j<21;j++){
        graph[10][j]='-';
    }
    graph[10][10]='+';
}
void print(){
    for(int i=0;i<21;i++){
        printf("%s\n",graph[i]);
    }
}
double sol(){
    stack<double> v;
    stack<int> op;
    double tmp,a,b;
    int dot,c;
    while(arr[pos]!=')'&&arr[pos]!=0){
        if(arr[pos]>='0'&&arr[pos]<='9'){
            tmp=0;
            dot=1;
            while(arr[pos]>='0'&&arr[pos]<='9'){
                tmp=tmp*10+arr[pos]-'0';
                pos++;
            }
            if(arr[pos]=='.'){
                pos++;
                while(arr[pos]>='0'&&arr[pos]<='9'){
                    tmp=tmp*10+arr[pos]-'0';
                    dot*=10;
                    pos++;
                }
            }
            v.push(tmp/dot);
        }else if(arr[pos]=='x'){
            pos++;
            v.push(X);
        }else if(arr[pos]=='s'){
            pos+=4;
            tmp=sin(sol());
            v.push(tmp);
        }else if(arr[pos]=='c'){
            pos+=4;
            tmp=cos(sol());
            v.push(tmp);
        }else if(arr[pos]=='l'){
            pos+=4;
            tmp=log10(sol());
            v.push(tmp);
        }else if(arr[pos]=='('){
            pos+=1;
            v.push(sol());
        }else if(arr[pos]=='^'){
            pos++;
            while(!op.empty()&&op.top()/5>=4){
                v.push(clc(v,op));
            }
            op.push(20);
        }else if(arr[pos]=='*'){
            pos++;
            while(!op.empty()&&op.top()/5>=3){
                v.push(clc(v,op));
            }
            op.push(15);
        }else if(arr[pos]=='/'){
            pos++;
            while(!op.empty()&&op.top()/5>=3){
                v.push(clc(v,op));
            }
            op.push(16);
        }else if(arr[pos]=='+'){
            pos++;
            while(!op.empty()&&op.top()/5>=2){
                v.push(clc(v,op));
            }
            op.push(10);
        }else if(arr[pos]=='-'){
            pos++;
            while(!op.empty()&&op.top()/5>=2){
                v.push(clc(v,op));
            }
            op.push(11);
        }else{
            pos++;
        }
    }
    pos++;
    while(!op.empty()){
        v.push(clc(v,op));
    }
    return v.top();
}
double clc(stack<double> &v,stack<int> &op){
    double a,b;
    int c;
    b=v.top();
    v.pop();
    a=v.top();
    v.pop();
    c=op.top();
    op.pop();
    switch(c){
    case 20:
        return pow(a,b);
    case 15:
        return a*b;
    case 16:
        return a/b;
    case 10:
        return a+b;
    case 11:
        return a-b;
    }
}
