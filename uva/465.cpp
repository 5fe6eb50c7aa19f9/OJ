#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
    unsigned long long a,b,ans,i,j;
    char op;
    string tmp1,tmp2;
    while(cin>>tmp1>>op>>tmp2){
        cout<<tmp1<<" "<<op<<" "<<tmp2<<endl;
        j=0;
        for(i=a=0;i<tmp1.size();i++){
            a=a*10+tmp1[i]-'0';
            if(a>0x7fffffff){
                printf("first number too big\n");
                a=0x80000000;
                break;
            }
        }
        for(i=b=0;i<tmp2.size();i++){
            b=b*10+tmp2[i]-'0';
            if(b>0x7fffffff){
                printf("second number too big\n");
                b=0x80000000;
                break;
            }
        }
        if(op=='*'&&a*b>0x7fffffff||op=='+'&&a+b>0x7fffffff){
            printf("result too big\n");
        }
    }
}
