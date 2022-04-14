#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int main(){
    int n;
    while(cin>>n){
        cout<<0+590*(n>=6&&n<=11)+790*(n>=12&&n<=17)+890*(n>=18&&n<=59)+399*(n>=60)<<endl;
    }
}
