#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int index,ans;
    string s;
};
node data[505];
bool cmps(node &a,node &b){
    if(a.s!=b.s)return a.s<b.s;
    return a.index<b.index;
}
bool cmpi(node &a,node &b){
    return a.index<b.index;
}
int main(){
    int n=0,i;
    while(getline(cin,data[n].s)){
        data[n].index=n;
        n++;
    }
    sort(data,data+n,cmps);
    data[0].ans=0;
    for(i=1;i<n;i++){
        if(data[i].s==data[i-1].s){
            data[i].ans=1;
        }else{
            data[i].ans=0;
        }
    }
    sort(data,data+n,cmpi);
    for(i=0;i<n;i++){
        if(data[i].ans){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}
