#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
#define Max(x,y) x>y?x:y
int N1[101];
int N2[101];
int ans[101][101];
int n1,n2;
int LCS(int s1,int s2){
    if(ans[s1][s2]!=-1){
        return ans[s1][s2];
    }
    if(N1[s1]!=N2[s2]){
        ans[s1][s2]=Max(LCS(s1-1,s2),LCS(s1,s2-1));
    }else{
        ans[s1][s2]=LCS(s1-1,s2-1)+1;
    }
    return ans[s1][s2];
}
int main(){
    int i,j,n=0;
    while(scanf("%d %d",&n1,&n2)){
        if(n1==0&&n2==0)break;
        n++;
        for(i=1;i<=n1;i++)scanf("%d",&N1[i]);
        for(i=1;i<=n2;i++)scanf("%d",&N2[i]);
        for(i=0;i<=n1;i++){
            for(j=0;j<=n2;j++){
                if(i==0||j==0){
                    ans[i][j]=0;
                }else{
                    ans[i][j]=-1;
                }
            }
        }
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",n,LCS(n1,n2));
    }
}
