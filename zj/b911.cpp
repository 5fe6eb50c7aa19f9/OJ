#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    unsigned long long n;
    while(cin>>n){
        int sum=0;;
        while(n!=0){
            n=(n>>1);
            sum++;
        }
        cout<<sum<<endl;
    }
}
