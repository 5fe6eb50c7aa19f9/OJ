#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n%4==0)cout<<"egg\n";
        else cout<<"fat\n";
    }
}
