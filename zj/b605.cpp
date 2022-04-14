#include <iostream>
#include <cstdio>
using namespace std;
int tp(int n){
    if(n==0)return 1;
    return tp(n-1)*2;
}
int main(){
    int data[7];
    while(cin>>data[0]){
        if(data[0]==-1)break;
        int need[7]={0};
        int flag=-1;
        if(data[0]!=0)flag=0;
        for(int i=1;i<7;i++){
            cin>>data[i];
            if(data[i]!=0)flag=i;
        }
        if(flag==-1){
            cout<<'0'<<endl;
            continue;
        }
        int L=tp(flag);
        data[flag]--;
        for(int i=6,now=64;i>=0;i--,now/=2){
            while(data[i]>0){
                if(need[i]==0){
                    need[i]=2*(L/now);
                    L+=now;
                }else need[i]--;
                data[i]--;
            }
            if(need[i]>0&&i-1>=0)need[i-1]+=need[i]*4;
        }
        cout<<L<<endl;
    }
}
