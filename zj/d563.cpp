#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        int* data=new int[n];
        int am=0;
        for(int i=0;i<n;i++)scanf("%d",&data[i]);
        int suf[n]={0};
        suf[n-1]=data[n-1];
        for(int i=n-2;i>=0;i--)suf[i]=data[i]+suf[i+1];
        for(int i=1;i<n;i++)data[i]+=data[i-1];
        for(int i=0,j=n-1;i<n;i++){
            for(int k=j;k>=0;k--){
                if(data[i]<=suf[k]){
                    j=k;
                    if(data[i]==suf[k])am++;
                    break;
                }
            }
        }
        cout<<am<<endl;
        delete []data;
    }
}
