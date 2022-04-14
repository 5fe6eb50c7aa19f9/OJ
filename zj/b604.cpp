#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n==0)break;
        long long data[n][2];
        long long x=0,y=0;
        for(int i=0;i<n;i++){
            cin>>data[i][0]>>data[i][1];
            x+=data[i][0];
            y+=data[i][1];
        }
        for(int i=0;i<n;i++){
            data[i][0]=data[i][0]*n-x;
            data[i][1]=data[i][1]*n-y;
        }
        bool detect[n]={false};
        bool flag=false;
        for(int i=0;i<n-1;i++){
            if(detect[i]==true)continue;
            for(int j=i+1;j<n;j++){
                if(data[i][0]+data[j][0]==0&&data[i][1]+data[j][1]==0){
                    detect[i]=true;
                    detect[j]=true;
                }
            }
            if(detect[i]!=true){
                flag=true;
                break;
            }
        }
        if(flag)cout<<"no\n";
        else cout<<"yes\n";
    }
}
