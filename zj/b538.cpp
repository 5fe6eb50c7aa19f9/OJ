#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a,int b){
    if(a<0)return gcd(-a,b);
    if(b<0)return gcd(a,-b);
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    long long data[2][2];
    char op;
    while(cin>>data[0][0]>>data[0][1]>>data[1][0]>>data[1][1]>>op){
        if(data[0][1]<0){
            data[0][0]*=-1;
            data[0][1]*=-1;
        }
        if(data[1][1]<0){
            data[1][0]*=-1;
            data[1][1]*=-1;
        }
        if(op=='+'||op=='-'){
            int tmp=gcd(data[0][1],data[1][1]);
            data[0][0]=data[0][0]*data[1][1]/tmp;
            data[1][0]=data[1][0]*data[0][1]/tmp;
            data[0][1]=data[0][1]*data[1][1]/tmp;
        }
        switch(op){
            case '+':data[0][0]+=data[1][0];break;
            case '-':data[0][0]-=data[1][0];break;
            case '*':data[0][0]*=data[1][0];data[0][1]*=data[1][1];break;
            case '/':data[0][0]*=data[1][1];data[0][1]*=data[1][0];break;
        }
        if(data[0][1]<0){
            data[0][0]*=-1;
            data[0][1]*=-1;
        }
        int tmp=gcd(data[0][0],data[0][1]);
        data[0][0]/=tmp;
        data[0][1]/=tmp;
        cout<<data[0][0];
        if(data[0][1]!=1)cout<<'/'<<data[0][1];
        cout<<endl;
    }
}
