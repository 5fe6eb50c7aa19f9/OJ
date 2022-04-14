#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

string data[2000];
int ptr[2000];
bool cmp(int &a,int &b){
    for(int i=0;i<data[a].size()&&i<data[b].size();i++){
        if(data[a][i]!=data[b][i])return data[a][i]<data[b][i];
    }
    return data[a].size()<data[b].size();
}
int main(){
    int n,i,j;
    string tmp;
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++){
            cin>>data[i];
            getline(cin,tmp);
            ptr[i]=i;
        }
        sort(ptr,ptr+n,cmp);
        for(i=1,j=1;i<n;i++){
            if(data[ptr[i]]==data[ptr[i-1]]){
                j++;
            }else if(data[ptr[i]]!=data[ptr[i-1]]){
                cout<<data[ptr[i-1]];
                printf(" %d\n",j);
                j=1;
            }
            if(i+1==n){
                cout<<data[ptr[i]];
                printf(" %d\n",j);
            }
        }
    }
}
