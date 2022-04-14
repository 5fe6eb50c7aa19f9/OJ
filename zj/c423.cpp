#include <cstdio>
#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> s;
string data;
int main(){
    int n,r,i,j,k;
    char tmp;
    scanf("%d %d",&n,&r);
    cin>>data;
    for(i=0,j=0;i<n-1;i++){
        k=data[i]-'0';
        j=(j+k)%10+(j+k)/10;
    }
    if(j!=r){
        r-=j;
        if(r<0)r+=9;
        tmp=r+'0';
        for(i=0;i<n;i++)s.insert(data.substr(0,i)+tmp+data.substr(i,n-1-i));
    }else{
        for(i=0;i<n;i++)s.insert(data.substr(0,i)+"0"+data.substr(i,n-1-i));
        for(i=0;i<n;i++)s.insert(data.substr(0,i)+"9"+data.substr(i,n-1-i));
    }
    set<string>::iterator it=s.begin();
    for(it++,i=1;i+1<s.size();it++,i++){
        cout<<*it<<endl;
    }
}
