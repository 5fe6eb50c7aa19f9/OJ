#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

double sqrt2=1/pow(2.0,0.5);
double dx[8]={0,sqrt2,1,sqrt2,0,0.0-sqrt2,-1,0.0-sqrt2};
double dy[8]={1,sqrt2,0,0.0-sqrt2,-1,0.0-sqrt2,0,sqrt2};
string buf;
int pos;
double getv(){
    int ret=0;
    while(pos<buf.size()&&buf[pos]>='0'&&buf[pos]<='9'){
        ret=ret*10+buf[pos++]-'0';
    }
    return (double)ret;
}
int getd(){
    int ret;
    if(buf[pos]=='N'&&buf[pos+1]=='E'){
        ret=1;
    }else if(buf[pos]=='S'&&buf[pos+1]=='E'){
        ret=3;
    }else if(buf[pos]=='S'&&buf[pos+1]=='W'){
        ret=5;
    }else if(buf[pos]=='N'&&buf[pos+1]=='W'){
        ret=7;
    }else if(buf[pos]=='N'){
        ret=0;
    }else if(buf[pos]=='E'){
        ret=2;
    }else if(buf[pos]=='S'){
        ret=4;
    }else if(buf[pos]=='W'){
        ret=6;
    }
    while(buf[pos]!=','&&buf[pos]!='.')pos++;
    return ret;
}
int main(){
    double i,j,v;
    int t=0,d;
    while(getline(cin,buf)&&buf!="END"){
        if(t++)printf("\n");
        i=j=0.0;
        pos=0;
        while(1){
            v=getv();
            d=getd();
            i+=dx[d]*v;
            j+=dy[d]*v;
            if(buf[pos++]=='.')break;
        }
        printf("Map #%d\n",t);
        printf("The treasure is located at (%.3f,%.3f).\n",i,j);
        printf("The distance to the treasure is %.3f.\n",sqrt(i*i+j*j));
    }
}
