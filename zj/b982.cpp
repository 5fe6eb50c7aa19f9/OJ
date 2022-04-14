#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
using namespace std;
int main(){
    string tmp;
    while(cin>>tmp){
        long long g=0,m=0,k=0,y=0,ii=0;
        if(tmp.find(".")>=0&&tmp.find(".")<tmp.size()){
            long long a=0,b=0;
            b+=(tmp[tmp.find(".")+1]-'0');
            for(int i=0;tmp[i]!='.';i++){
                a*=10;
                a+=tmp[i]-'0';
            }
            if(tmp.find("k")>=0&&tmp.find("k")<tmp.size()){
                cout<<a*8000+b*800<<endl;
            }else{
                cout<<a*8+b<<endl;
            }
            continue;
        }
        int flag;
        flag=tmp.find("g");
        if(flag>=0&&flag<tmp.size()){
            for(int i=flag-1,rate=1;i>=0&&tmp[i]>='0'&&tmp[i]<='9';i--,rate*=10){
                g+=(tmp[i]-'0')*rate;
            }
        }
        flag=tmp.find("m");
        if(flag>=0&&flag<tmp.size()){
            for(int i=flag-1,rate=1;i>=0&&tmp[i]>='0'&&tmp[i]<='9';i--,rate*=10){
                m+=(tmp[i]-'0')*rate;
            }
        }
        flag=tmp.find("k");
        if(flag>=0&&flag<tmp.size()){
            for(int i=flag-1,rate=1;i>=0&&tmp[i]>='0'&&tmp[i]<='9';i--,rate*=10){
                k+=(tmp[i]-'0')*rate;
            }
        }
        flag=tmp.find("y");
        if(flag>=0&&flag<tmp.size()){
            for(int i=flag-2,rate=1;i>=0&&tmp[i]>='0'&&tmp[i]<='9';i--,rate*=10){
                y+=(tmp[i]-'0')*rate;
            }
        }
        flag=tmp.find("i");
        if(flag>=0&&flag<tmp.size()){
            for(int i=flag-2,rate=1;i>=0&&tmp[i]>='0'&&tmp[i]<='9';i--,rate*=10){
                ii+=((tmp[i]-'0')*rate);
            }
        }
        cout<<g*8000000000+m*8000000+k*8000+y*8+ii<<endl;
    }
}
