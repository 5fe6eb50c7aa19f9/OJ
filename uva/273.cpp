#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct edge{
    int x1,y1,x2,y2;
};
edge e[12];
int p[12];//union&find set
int Find(int i){
    return p[i]==i?i:p[i]=Find(p[i]);
}
inline int cross(int i,int px,int py){
    return (e[i].x2-e[i].x1)*(py-e[i].y1)-(e[i].y2-e[i].y1)*(px-e[i].x1);
}
inline int joint(int i,int px,int py){
    if(px<e[i].x1||px>e[i].x2)return 0;
    if(py>e[i].y1&&py>e[i].y2)return 0;
    if(py<e[i].y1&&py<e[i].y2)return 0;
    return 1;
}
bool cmp(int i,int j){
    int r1=cross(i,e[j].x1,e[j].y1);
    int r2=cross(i,e[j].x2,e[j].y2);
    int r3=cross(j,e[i].x1,e[i].y1);
    int r4=cross(j,e[i].x2,e[i].y2);
    if(r1*r2<0&&r3*r4<0)return 1;
    if(r1==0&&joint(i,e[j].x1,e[j].y1))return 1;
    if(r2==0&&joint(i,e[j].x2,e[j].y2))return 1;
    if(r3==0&&joint(j,e[i].x1,e[i].y1))return 1;
    if(r4==0&&joint(j,e[i].x2,e[i].y2))return 1;
    return 0;
}
int main(){
    int t,i,j,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d %d %d %d",&e[i].x1,&e[i].y1,&e[i].x2,&e[i].y2);
            if(e[i].x1>e[i].x2){
                swap(e[i].x1,e[i].x2);
                swap(e[i].y1,e[i].y2);
            }
            p[i]=i;
        }
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(cmp(i,j)){
                    p[Find(i)]=Find(j);
                }
            }
        }
        while(scanf("%d %d",&i,&j)==2&&i+j){
            if(Find(i-1)==Find(j-1)){
                printf("CONNECTED\n");
            }else{
                printf("NOT CONNECTED\n");
            }
        }
        if(t)printf("\n");
    }
}
