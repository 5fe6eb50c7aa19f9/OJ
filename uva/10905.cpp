#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

string data[50];
int ptr[50];
bool cmp(int a,int b){
    int tmp1=a,tmp2=b,L=data[a].size()+data[b].size();
    for(int i=0,j=0,k=0;i<L;i++,j++,k++){
        if(j==data[a].size()){
            j=0;
            a=tmp2;
        }
        if(k==data[b].size()){
            k=0;
            b=tmp1;
        }
        if(data[a][j]!=data[b][k])return data[a][j]>data[b][k];
    }
    return true;
}
int main(){
    int n,i,j;
    while(scanf("%d",&n)==1&&n!=0){
        for(i=0;i<n;i++){
            cin>>data[i];
            ptr[i]=i;
        }
        sort(ptr,ptr+n,cmp);
        for(i=0;i<n;i++){
            cout<<data[ptr[i]];
        }
        printf("\n");
    }
}
