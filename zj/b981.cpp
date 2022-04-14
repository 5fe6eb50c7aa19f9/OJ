#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    string data;
    while(cin>>data){
        if(data[data.size()-1]=='s'&&data[data.size()-2]=='m'){
            data[data.size()-1]='S';
            data[data.size()-2]='M';
        }
        bool h=false,m=false,s=false,ms=false,dot=false;
        for(int i=0;i<data.size();i++){
            if(data[i]=='h')h=true;
            if(data[i]=='m')m=true;
            if(data[i]=='s')s=true;
            if(data[i]=='M')ms=true;
            if(data[i]=='.')dot=true;
        }
        int sum=0;
        if(h&&m&&s){
            for(int i=0,tmp=0,rate=3600000;i<data.size();i++){
                if(!(data[i]<='9'&&data[i]>='0')){
                    sum+=(tmp*rate);
                    rate/=60;
                    tmp=0;
                    while(!(data[i]<='9'&&data[i]>='0')&&i<data.size())i++;
                    i--;
                    continue;
                }
                tmp*=10;
                tmp+=data[i]-'0';
            }
        }else if(h&&m){
            for(int i=0,tmp=0,rate=3600000;i<data.size();i++){
                if(!(data[i]<='9'&&data[i]>='0')){
                    sum+=(tmp*rate);
                    rate/=60;
                    tmp=0;
                    while(!(data[i]<='9'&&data[i]>='0')&&i<data.size())i++;
                    i--;
                    continue;
                }
                tmp*=10;
                tmp+=data[i]-'0';
            }
        }else if(h){
            for(int i=0,tmp=0,rate=3600000;i<data.size();i++){
                if(!(data[i]<='9'&&data[i]>='0')){
                    sum+=(tmp*rate);
                    rate/=60;
                    tmp=0;
                    while(!(data[i]<='9'&&data[i]>='0')&&i<data.size())i++;
                    i--;
                    continue;
                }
                tmp*=10;
                tmp+=data[i]-'0';
            }
        }else if(m&&s){
            for(int i=0,tmp=0,rate=60000;i<data.size();i++){
                if(!(data[i]<='9'&&data[i]>='0')){
                    sum+=(tmp*rate);
                    rate/=60;
                    tmp=0;
                    while(!(data[i]<='9'&&data[i]>='0')&&i<data.size())i++;
                    i--;
                    continue;
                }
                tmp*=10;
                tmp+=data[i]-'0';
            }
        }else if(m){
            for(int i=0,tmp=0,rate=60000;i<data.size();i++){
                if(!(data[i]<='9'&&data[i]>='0')){
                    sum+=(tmp*rate);
                    rate/=60;
                    tmp=0;
                    while(!(data[i]<='9'&&data[i]>='0')&&i<data.size())i++;
                    i--;
                    continue;
                }
                tmp*=10;
                tmp+=data[i]-'0';
            }
        }else if(dot&&s){
            for(int i=0,tmp=0,rate=1000;i<data.size();i++){
                if(!(data[i]<='9'&&data[i]>='0')){
                    sum+=(tmp*rate);
                    sum+=(data[i+1]-'0')*100;
                    break;
                }
                tmp*=10;
                tmp+=data[i]-'0';
            }
        }else if(s){
            for(int i=0,tmp=0,rate=1000;i<data.size();i++){
                if(!(data[i]<='9'&&data[i]>='0')){
                    sum+=(tmp*rate);
                    rate/=10;
                    tmp=0;
                    while(!(data[i]<='9'&&data[i]>='0')&&i<data.size())i++;
                    i--;
                    continue;
                }
                tmp*=10;
                tmp+=data[i]-'0';
            }
        }else if(ms){
            for(int i=0,tmp=0,rate=1;i<data.size();i++){
                if(!(data[i]<='9'&&data[i]>='0')){
                    sum+=(tmp*rate);
                    rate/=10;
                    tmp=0;
                    while(!(data[i]<='9'&&data[i]>='0')&&i<data.size())i++;
                    i--;
                    continue;
                }
                tmp*=10;
                tmp+=data[i]-'0';
            }
        }
        cout<<sum<<endl;
    }
}
