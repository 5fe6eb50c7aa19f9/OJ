#include <cstdio>
#include <iostream>
using namespace std;

int x,y,ans;
void dfs(int i,int j,int k){
    if(k==0)return;
    if(x>=i-k&&x<=i+k&&y>=j-k&&y<=j+k)ans++;
    dfs(i-k,j-k,k/2);
    dfs(i-k,j+k,k/2);
    dfs(i+k,j-k,k/2);
    dfs(i+k,j+k,k/2);
}
int main(){
    int k,i;
    while(scanf("%d %d %d",&k,&x,&y)&&!(k==0&&x==0&&y==0)){
        ans=0;
        dfs(1024,1024,k);
        printf("%3d\n",ans);
    }
}
