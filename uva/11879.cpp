#include <iostream>
#include <cstdio>
using namespace std;

string data;
int main(){
    int i,j;
    while(getline(cin,data)&&data!="0"){
        for(i=j=0;i<data.size();i++){
            j=j*10+data[i]-'0';
            j%=17;
        }
        printf("%d\n",j==0);
    }
}
