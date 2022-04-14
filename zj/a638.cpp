#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
    double x,y;
};
char buf[50000000];
node data[3000000];
double ret;
double DC(int l,int r){
    if(l+1==r){
        return 1e15;
    }else if(l+2==r){
        return (data[l].x-data[l+1].x)*(data[l].x-data[l+1].x)+(data[l].y-data[l+1].y)*(data[l].y-data[l+1].y);
    }
    int m=(l+r)>>1,i,j,bound=data[m-1].x;
    ret=min(ret,DC(l,m));
    ret=min(ret,DC(m,r));
    for(i=m-1;i>=l;i--){
        if((data[i].x-bound)*(data[i].x-bound)>=ret)break;
        for(j=m;j<r;j++){
            if((data[j].x-data[i].x)*(data[j].x-data[i].x)>=ret)break;
            ret=min(ret,(data[i].x-data[j].x)*(data[i].x-data[j].x)+(data[i].y-data[j].y)*(data[i].y-data[j].y));
        }
    }
    return ret;
}
int main(){
    int n,i,j,k;
    scanf("%d\n",&n);
    scanf("%[^eof]",buf);
    for(i=j=n=k=0;buf[i];i++){
        if(buf[i]>='0'&&buf[i]<='9'){
            j=(j<<3)+(j<<1)+buf[i]-'0';
        }else{
            if(!k){
                data[n].x=j;
                k=1;
            }else{
                data[n++].y=j;
                k=0;
            }
            j=0;
        }
    }
    ret=1e15;
    printf("%.4lf\n",sqrt(DC(0,n)));
}
