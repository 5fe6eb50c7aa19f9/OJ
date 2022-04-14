#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

int tree[1000000];
int v[1000000];
int t,cnt;
string data;
queue<int> ans;
bool sol(){
    int i=1,j=0,k=1;
    while(data[i]>='0'&&data[i]<='9'){
        j=j*10+data[i++]-'0';
    }
    i++;
    while(data[i]!=')'){
        if(data[i]=='L')k=k*2;
        else k=k*2+1;
        i++;
    }
    if(tree[k]==t)return 0;
    tree[k]=t;
    if(k/2&&tree[k/2]!=t)cnt++;
    if(tree[k*2]==t)cnt--;
    if(tree[k*2+1]==t)cnt--;
    v[k]=j;
    return 1;
}
int main(){
    int i,j,k,flag;
    while(cin>>data){
        t++;
        cnt=flag=0;
        if(!sol())flag=1;
        while(cin>>data){
            if(data=="()")break;
            if(!sol())flag=1;
        }
        if(cnt||flag){
            printf("not complete\n");
        }else{
            ans.push(1);
            while(!ans.empty()){
                i=ans.front();
                ans.pop();
                if(tree[i*2]==t)ans.push(i*2);
                if(tree[i*2+1]==t)ans.push(i*2+1);
                if(i!=1)printf(" ");
                printf("%d",v[i]);
            }
            printf("\n");
        }
    }
}
