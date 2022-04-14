#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long go(long long a,long long b){
    long long tmp1=(a*100+50)*log10(a);
    long long tmp2=50*log10(2*3.1416);
    long long tmp3=(b*100+50)*log10(b);
    long long tmp4=(a*100-b*100+50)*log10(a-b);
    return tmp1-tmp2-tmp3-tmp4;
}
int main(){
    long long a,b;
    while(cin>>a>>b){
        if(a==b){
            cout<<'1'<<endl;
            continue;
        }
        long long ans=go(a,b)/100+1;
        cout<<ans<<endl;
    }
}
