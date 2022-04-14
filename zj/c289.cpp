#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

string data[100000];
int ptr[100000];
bool cmp(int &a,int &b){
    for(int i=0;i<data[a].size()&&i<data[b].size();i++){
        if(data[a][i]!=data[b][i])return data[a][i]<data[b][i];
    }
    return data[a].size()<data[b].size();
}
int main(){
    int n,i,j,ans;
    string tmp;
    while(scanf("%d",&n)==1&&n){
        getline(cin,tmp);
        for(i=0;i<n;i++){
            getline(cin,data[i]);
            ptr[i]=i;
        }
        sort(ptr,ptr+n,cmp);
        ans=0;
        for(i=1;i<n;i++){
            for(j=0;j<data[ptr[i]].size()&&j<data[ptr[i-1]].size();j++){
                if(data[ptr[i]][j]!=data[ptr[i-1]][j])break;
            }
            ans=max(ans,j);
        }
        printf("%d\n",ans);
    }
}
