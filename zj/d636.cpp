#include <iostream>
#include <cstdio>
using namespace std;

int go(int a,int b){
    if(b==0)return 1;
    if(b%2==0){
        int tmp=go(a,b/2);
        tmp=tmp*tmp%10007;
        return tmp;
    }else{
        int tmp=go(a,b/2);
        tmp=tmp*tmp%10007;
        return tmp*a%10007;
    }
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<go(a%10007,b)%10007;
}
