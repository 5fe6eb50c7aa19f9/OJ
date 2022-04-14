#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int sum,c,w;
void go(){
    if(c+w<13||w<1)return;
    if(c>=12&&w>=1){
        c-=11;
        w--;
        c++;
        sum++;
        //cout<<c<<' '<<w<<endl;
    }else if(12-c<w){
        w=w+c-13;
        c=2;
        sum++;
        //cout<<c<<' '<<w<<endl;
    }
    go();
}
int main(){
    while(cin>>c>>w){
         sum=0;
         go();
         cout<<sum<<endl;
    }
}
