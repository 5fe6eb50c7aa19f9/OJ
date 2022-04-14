#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool ans;
string data;
int go(int i){
    if(i==data.size())return i;
    if(data[i]==')'||data[i]==']'){
        return i;
    }
    int j=go(i+1);
    if(j<data.size()){
        if(data[i]=='('&&data[j]!=')')ans=0;
        if(data[i]=='['&&data[j]!=']')ans=0;
        return go(j+1);
    }
    ans=0;
    return j;
}
int main(){
    int n,i;
    scanf("%d",&n);
    getline(cin,data);
    while(n--){
        getline(cin,data);
        if(data==""){
            printf("Yes\n");
            continue;
        }
        ans=1;
        if(data.size()%2==0||data[0]=='('||data[0]=='['){
            if(go(0)!=data.size())ans=0;
        }else{
            ans=0;
        }
        if(ans){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}
