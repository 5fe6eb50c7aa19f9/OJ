#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int area[400];
int main(){
    int i,j,a,b,l,r,m,flag1,flag2;
    for(i=1;i<400;i++){
        area[i]=i*i;
    }
    while(scanf("%d %d",&a,&b)==2&&!(a==0&&b==0)){
        l=1,r=400;
        while(l<r){
            m=(l+r)>>1;
            if(area[m]>a){
                flag1=m;
                r=m;
            }else if(area[m]<a){
                l=m+1;
            }else{
                flag1=m;
                break;
            }
        }
        l=1,r=400;
        while(l<r){
            m=(l+r)>>1;
            if(area[m]>b){
                r=m;
            }else if(area[m]<b){
                flag2=m;
                l=m+1;
            }else{
                flag2=m;
                break;
            }
        }
        if(flag1<=flag2)printf("%d\n",flag2-flag1+1);
        else printf("0\n");
    }
}
