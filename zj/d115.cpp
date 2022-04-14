#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int tmp[10000];
void go(int* data,int n,int now,int m){
    if(now==m){
        for(int i=0;i<m;i++)cout<<tmp[i]<<' ';
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        tmp[now]=data[i];
        go(data+i+1,n-i-1,now+1,m);
    }
}
int main(){
    int n;
    while(cin>>n){
        if(n==0)break;
        int data[n];
        int m;
        for(int i=0;i<n;i++)cin>>data[i];
        cin>>m;
        sort(data,data+n);
        go(data,n,0,m);
    }
}
