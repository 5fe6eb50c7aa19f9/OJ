#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int n;
int main(){
    string data;
    long long a,b,i,j;
    while(getline(cin,data)){
        a=0,b=0;
        i=data.size()-1;
        if(data[i]=='i'){
            for(i=data.size()-2,j=1;i>=0&&data[i]>='0'&&data[i]<='9';i--,j*=10){
                b+=(data[i]-'0')*j;
            }
            if(b==0)b=1;
            i--;
        }
        for(j=1;i>=0&&data[i]>='0'&&data[i]<='9';i--,j*=10){
            a+=(data[i]-'0')*j;
        }
        printf("%.3f\n",sqrt(a*a+b*b));
    }
}
