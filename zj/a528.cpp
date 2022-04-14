#include <iostream>
#include <cstdio>
using namespace std;

bool compare(string a,string b){
    if(b[0]=='-'&&a[0]!='-')return true;
    if(b[0]!='-'&&a[0]=='-')return false;
    if(b[0]!='-'&&a[0]!='-'){
        if(a.size()>b.size())return true;
        if(a.size()<b.size())return false;
        for(int i=0;i<a.size();i++){
            if(a[i]>b[i])return true;
            if(a[i]==b[i])continue;
            if(a[i]<b[i])return false;
        }
        return false;
    }
    if(a.size()>b.size())return false;
    if(a.size()<b.size())return true;
    for(int i=1;i<a.size();i++){
        if(a[i]>b[i])return false;
        if(a[i]==b[i])continue;
        if(a[i]<b[i])return true;
    }
    return false;
}
int main()
{
    int a;
    while(cin>>a){
        cin.ignore();
        string data[a];
        for(int i=0;i<a;i++){
            getline(cin,data[i]);
        }
        for(int i=0;i<a-1;i++){
            int tmp=i;
            for(int j=i+1;j<a;j++){
                if(compare(data[tmp],data[j])){
                    tmp=j;
                }
            }
            string tmpstr(data[tmp]);
            data[tmp]=data[i];
            data[i]=tmpstr;
        }
        for(int i=0;i<a;i++){
            cout<<data[i]<<endl;
        }
    }
}
