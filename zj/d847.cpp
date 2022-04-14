#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
    int x,y,num,i;
    bool operator<(node &b){
        if(x!=b.x)return x<b.x;
        return y>b.y;
    }
};
node data[10000];
node tmp[10000];
void DnC(int l,int r){
    if(l+1==r){
        return;
    }
    int m=(l+r)>>1,i,j,k;
    DnC(l,m),DnC(m,r);
    for(i=l,j=l,k=m;i<r;i++){
        if(j==m){
            data[k].num+=j-l;//
            tmp[i]=data[k++];
        }else if(k==r){
            tmp[i]=data[j++];
        }else if(data[j].y>=data[k].y){
            data[k].num+=j-l;//
            tmp[i]=data[k++];
        }else{
            tmp[i]=data[j++];
        }
    }
    for(i=l;i<r;i++){
        data[i]=tmp[i];
    }
}
int main(){
    int i,n;
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++){
            scanf("%d %d",&data[i].x,&data[i].y);
            data[i].num=0;
            data[i].i=i;
        }
        sort(data,data+n);
        DnC(0,n);
        for(i=0;i<n;i++){
            tmp[data[i].i]=data[i];
        }
        for(i=0;i<n;i++){
            printf("%d\n",tmp[i].num);
        }
    }
}
