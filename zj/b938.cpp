#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m){
        bool data[n+1]={false};
        for(int i=0,tmp;i<m;i++){
            cin>>tmp;
            if(data[tmp]){
                cout<<"0u0 ...... ?\n";
                continue;
            }
            int flag=-1;
            for(int j=tmp+1;j<=n;j++){
                if(!data[j]){
                    data[j]=true;
                    flag=j;
                    break;
                }
            }
            if(flag!=-1){
                cout<<flag<<endl;
            }else{
                cout<<"0u0 ...... ?\n";
            }
        }
    }
}
