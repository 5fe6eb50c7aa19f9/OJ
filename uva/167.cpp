#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int data[8][8],ans;
int visit[8][8];
void setting(int r,int c,int v){
    int i,j;
    for(i=r+1,j=c;i<8;i++){
        visit[i][j]+=v;
    }
    for(i=r+1,j=c+1;i<8&&j<8;i++,j++){
        visit[i][j]+=v;
    }
    for(i=r+1,j=c-1;i<8&&j>=0;i++,j--){
        visit[i][j]+=v;
    }
}
void sol(int i,int sum){
    if(i==8){
        ans=max(ans,sum);
        return;
    }
    for(int j=0;j<8;j++){
        if(!visit[i][j]){
            setting(i,j,1);
            sol(i+1,sum+data[i][j]);
            setting(i,j,-1);
        }
    }
}
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                scanf("%d",data[i]+j);
            }
        }
        ans=0;
        sol(0,0);
        printf("%5d\n",ans);
    }
}
