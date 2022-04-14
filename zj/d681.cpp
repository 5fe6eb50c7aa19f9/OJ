#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int main(){
    string data;
    while(getline(cin,data)){
        string last="     ";
        int i=0;
        for(;i<5;i++)last[i]=data[i];
        cout<<last;
        while(true){
            i++;
            bool flag;
            string tmp="     ";
            if(data[i]=='o'){
                flag=false;
                i+=3;
            }else{
                flag=true;
                i+=4;
            }
            for(int j=0;j<5;i++,j++)tmp[j]=data[i];
            if(!flag){
                for(int j=0;j<5;j++){
                    if(last[j]=='1'||tmp[j]=='1')last[j]='1';
                }
            }else{
                for(int j=0;j<5;j++){
                    if(!(last[j]=='1'&&tmp[j]=='1'))last[j]='0';
                }
            }
            cout<<(flag?"&&":"||")<<tmp;
            if(data[i+1]!='a'&&data[i+1]!='o')break;
        }
        cout<<" = "<<last<<endl;
    }
}
