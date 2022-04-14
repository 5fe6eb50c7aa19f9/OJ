#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    string tc="mjqhofawcpnsexdkvgtzblryui";
    string ti="uzrmatifxopnhwvbslekycqjgd";
    int n;
    while(cin>>n){
        for(int m=0;m<n;m++){
            int a;
            cin>>a;
            cin.ignore();
            string data[a];
            for(int i=0;i<a;i++)cin>>data[i];
            if(data[0][0]>='a'&&data[0][0]<='z'){
                int sum=0;
                for(int i=0;i<a;i++)sum+=ti.find(data[i][0])+1;
                cout<<sum<<endl;
            }else{
                for(int i=0,tmp;i<a;i++){
                    tmp=data[i][0]-'0';
                    if(data[i].size()==2){
                        tmp=tmp*10+data[i][1]-'0';
                    }
                    cout<<tc[tmp-1];
                }
                cout<<endl;
            }
        }
    }
}
