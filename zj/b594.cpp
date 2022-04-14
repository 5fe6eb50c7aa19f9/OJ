#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n==0)break;
        int num=0;
        for(int i=2;i<n;i++){
            if(n*2%i==0&&(n*2/i+1-i)>1&&(n*2/i+1-i)%2==0)num++;
        }
        cout<<num<<endl;
    }
}
