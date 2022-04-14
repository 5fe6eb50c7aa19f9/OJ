#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int main(){
    int n,a,b;
    while(cin>>n>>a>>b){
        bool data[32]={false};
        if(n<0){
            n+=0x7fffffff+1;
            data[0]=true;
        }
        for(int i=31;i>=0;i--){
            if(n%2==1)data[i]=true;
            n/=2;
        }
        data[31-a]=(b==1);
        for(int i=0;i<32;i++)cout<<data[i];
        cout<<endl;
    }
}
