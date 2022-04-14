#include <iostream>
#include <cstdio>
using namespace std;

unsigned long long sum;
int gcd(int a,int b){
    if(b==0)return a;
    gcd(b,a%b);
}
void go(int s,int m){
    if(s==m){
        sum=1;
        return;
    }
    if(s>m){
        go(s-m,m);
        sum*=2;
        return;
    }else{
        go(m-s,s);
        sum=sum*2+1;
        return;
    }
}
int main(){
    int s,m;
    while(cin>>s>>m){
        int tmp=gcd(s,m);
        s/=tmp;
        m/=tmp;
        go(s,m);
        cout<<sum<<endl;
    }
}
