#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int data[100000];
int tmp[100000];
int res;
void MS(int l,int r){
    if(l+1==r){
        return;
    }
    int m=(l+r)>>1,i,j,k;
    MS(l,m);
    MS(m,r);
    for(i=l,j=l,k=m;i<r;i++){
        if(j==m){
            tmp[i]=data[k++];
        }else if(k==r){
            tmp[i]=data[j++];
            res+=k-m;
        }else if(data[j]<data[k]){
            tmp[i]=data[j++];
            res+=k-m;
        }else{
            tmp[i]=data[k++];
        }
    }
    for(i=l;i<r;i++){
        data[i]=tmp[i];
    }
}
int main(){
    int i,j,n;
    while(scanf("%d",&n)==1&&n){
        for(i=0;i<n;i++)scanf("%d",data+i);
        res=0;
        MS(0,n);
        if(res&1){
            printf("Marcelo\n");
        }else{
            printf("Carlos\n");
        }
    }
}
