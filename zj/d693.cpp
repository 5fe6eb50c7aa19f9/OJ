#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    int n;
    while(true){
        cin>>n;
        if(n==0)break;
        long long data[n];
        long long lc=1;
        for(int i=0;i<n;i++)cin>>data[i];
        for(int i=0;i<n;i++){
            long long tmp=gcd(lc,data[i]);
            lc=data[i]*lc/tmp;
        }
        cout<<lc<<endl;
    }
}
