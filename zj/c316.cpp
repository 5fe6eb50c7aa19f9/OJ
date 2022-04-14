#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct point{
    int x,y;
};
point data[1000];
int main(){
    int n,i,j,a,b,d;
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++){
            scanf("%d %d",&data[i].x,&data[i].y);
        }
        d=0;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if((data[i].x-data[j].x)*(data[i].x-data[j].x)+(data[i].y-data[j].y)*(data[i].y-data[j].y)>d){
                    d=(data[i].x-data[j].x)*(data[i].x-data[j].x)+(data[i].y-data[j].y)*(data[i].y-data[j].y);
                    a=i,b=j;
                }
            }
        }
        printf("%d %d\n",a,b);
    }
}
