#include <iostream>
#include <cstdio>
using namespace std;
long long data[6];
long long sq(long long x,int n){
    if(n==0)return 1;
    return x*sq(x,n-1);
}
int po(long long x){
    long long tmp=data[0]+data[1]*sq(x,1)+data[2]*sq(x,2)+data[3]*sq(x,3)+data[4]*sq(x,4)+data[5]*sq(x,5);
    if(tmp==0){
        return 0;
    }else if(tmp>0){
        return 1;
    }else{
        return -1;
    }
}

int main(){
    while(cin>>data[5]){
        int flag=-1;
        for(int i=4;i>=0;i--){
            cin>>data[i];
            if(data[i]!=0&&flag==-1)flag=i;
        }
        if(flag==-1||flag==0){
            cout<<"Too many... = =\"\n";
            continue;
        }
        bool flag2=false;
        for(int i=-75,now=po(i);i<=75;i++){
            int next=po(i+1);
            if(next==0){
                cout<<i+1<<' '<<i+1<<endl;
                flag2=true;
            }else if(next*now<0){
                cout<<i<<' '<<i+1<<endl;
                flag2=true;
            }
            now=next;
        }
        if(!flag2)cout<<"N0THING! >\\\\\\<\n";
    }
}
