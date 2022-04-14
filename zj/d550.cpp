#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int data[10000][200];
bool cmp(int x,int y,int b){
    for(int i=0;i<b;i++){
        if(data[x][i]<data[y][i])return true;
        if(data[x][i]>data[y][i])return false;
    }
    return true;
}
void go(int* tmp,int a,int b){
    if(a==1)return;
    go(tmp,a/2,b);
    go(tmp+a/2,a/2+a%2,b);
    int le[a/2];
    int ri[a/2+a%2];
    for(int i=0;i<a/2;i++)le[i]=tmp[i];
    for(int i=0;i<a/2+a%2;i++)ri[i]=tmp[i+a/2];
    for(int i=0,l=0,r=0;i<a;i++){
        if(r==a/2+a%2||(l<a/2&&cmp(le[l],ri[r],b))){
            tmp[i]=le[l];
            l++;
        }else{
            tmp[i]=ri[r];
            r++;
        }
    }
}
int main(){
    int a,b;
    while(cin>>a>>b){
        int tmp[a];
        for(int i=0;i<a;i++){
            tmp[i]=i;
            for(int j=0;j<b;j++)scanf("%d",&data[i][j]);
        }
        go(tmp,a,b);
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++)printf("%d ",data[tmp[i]][j]);
            cout<<endl;
        }
    }
}
