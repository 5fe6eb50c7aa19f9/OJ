#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    while(cin>>n){
        int sum=0;
        for(long long i=5;i<=n;i*=5){
            sum+=n/i;
        }
        cout<<sum<<endl;
    }
}
