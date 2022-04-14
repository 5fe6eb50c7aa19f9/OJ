#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    long long n,m;
    while(cin>>n>>m){
        if(m==0){
            cout<<"Go Kevin!!\n";
            continue;
        }
        for(int i=1;;i+=m){
            if(n<=0){
                if(n==0)cout<<"Go Kevin!!\n";
                else cout<<"No Stop!!\n";
                break;
            }
            n-=i;
        }
    }
}
