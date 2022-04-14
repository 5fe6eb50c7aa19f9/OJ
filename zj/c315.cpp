#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
    int n,x,y,i,j,k;
    while(scanf("%d",&n)==1){
        x=y=0;
        while(n--){
            scanf("%d %d",&i,&j);
            x+=dx[i]*j;
            y+=dy[i]*j;
        }
        printf("%d %d\n",x,y);
    }
}
