#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long go(int n){
    if(n==0)return 1;
    return 10*go(n-1);
}
int main(){
    string a;
    while(getline(cin,a)){
        long long ev=0,od=0;
        for(int i=0;i<a.size();i++){
            if(a[i]==':'){
                int ten=7;
                int tmp1;
                long long tmp2=0;
                tmp1=a[i-1]-'0';
                bool dot=false,s=false;
                if(a[i+1]=='-'){//note that there will be '-' in test data
                    s=true;
                    i++;
                }
                for(int j=i+1;j<a.size()&&a[j]!=' ';j++){
                    if(a[j]=='.'){
                        dot=true;
                        continue;
                    }
                    if(dot)ten--;
                    tmp2*=10;
                    tmp2+=a[j]-'0';
                    i=j;
                }
                if(s)tmp2*=-1;
                if(tmp1%2==0){
                    ev+=tmp2*go(ten);
                }else{
                    od+=tmp2*go(ten);
                }
            }
        }
        if(od>=ev){
            long long tmp=10000000;
            cout<<(od-ev)/tmp;
            od=(od-ev)%tmp;
            if(od==0){
                cout<<endl;
                continue;
            }
            while(od%tmp!=0){
                tmp/=10;
            }
            cout<<'.'<<od/tmp<<endl;
        }else{
            long long tmp=10000000;
            cout<<'-'<<(ev-od)/tmp;
            ev=(ev-od)%tmp;
            if(ev==0){
                cout<<endl;
                continue;
            }
            while(ev%tmp!=0){
                tmp/=10;
            }
            cout<<'.'<<ev/tmp<<endl;
        }
    }
}
