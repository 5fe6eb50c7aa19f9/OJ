#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    bool data[1001]={false};
    for(int i=2;i<=1000;i++){
        if(data[i])continue;
        for(int j=i*i;j<=1000;j+=i)data[j]=true;
    }
    for(int i=2;i<=1000;i++){
        if(data[i])continue;
        for(int j=i*i;j<=1000;j*=i)data[j]=false;
    }
    int datai[1001]={0};
    for(int i=2,sum=0;i<=1000;i++){
        if(!data[i])sum++;
        datai[i]=sum;
    }
    int n;
    while(cin>>n){
        cout<<datai[n]<<endl;
        for(int i=2;i<=n;i++){
            if(!data[i])cout<<i<<' ';
        }
        cout<<endl;
    }
}
