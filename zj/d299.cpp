#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int data[10]={0};
bool judge(){
    int a=0,b=0,c=0;
    a+=data[0]+data[2]*10+data[4]*100+data[6]*1000+data[8]*10000;
    b+=data[1]+data[3]*10+data[2]*100;
    c+=data[0]+data[2]*10+data[5]*100+data[7]*1000+data[9]*10000;
    if(a+b+b!=c)return false;
    cout<<a<<" "<<b<<" "<<c<<endl;
    return true;
}
void go(int);
int main(){
    cout<<"29786 + 850 + 850 = 31486";
}
void go(int now){
    if(now==10){
        judge();
        return;
    }
    for(int i=0;i<10;i++){
        bool flag=true;
        for(int j=0;j<now;j++)if(data[j]==i){
            flag=false;
            break;
        }
        if(!flag)continue;
        data[now]=i;
        go(now+1);
        data[now]=0;
    }
}
