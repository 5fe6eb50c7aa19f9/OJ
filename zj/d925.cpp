#include <iostream>
#include <cstdio>
using namespace std;

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int main(){
    int m,n,t,x,y,k,i,j,sum=0;
    scanf("%d %d %d",&m,&n,&t);
    while(t--){
        scanf("%d %d %d",&x,&y,&k);
        for(i=0,j=-1;i<8;i++){
            if(x+dx[i]>=1&&x+dx[i]<=m&&y+dy[i]>=1&&y+dy[i]<=n)j++;
        }
        sum+=k*j;
    }
    printf("%.2lf\n",(double)sum/(m*n));
}
