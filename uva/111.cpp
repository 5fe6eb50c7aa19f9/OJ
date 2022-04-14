#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
int N1[21];
int N2[21];
int ans[21][21];
int LCS(int s1,int s2){
    if(ans[s1][s2]!=-1){
        return ans[s1][s2];
    }
    if(N1[s1]!=N2[s2]){
        ans[s1][s2]=max(LCS(s1-1,s2),LCS(s1,s2-1));
    }else{
        ans[s1][s2]=LCS(s1-1,s2-1)+1;
    }
    return ans[s1][s2];
}
int main(){
    int i,j,n,tmp;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&tmp);
        N1[tmp]=i;
    }
    while(cin>>tmp){
        N2[tmp]=1;
        for(i=2;i<=n;i++){
            scanf("%d",&tmp);
            N2[tmp]=i;
        }
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                if(i==0||j==0){
                    ans[i][j]=0;
                }else{
                    ans[i][j]=-1;
                }
            }
        }
        printf("%d\n",LCS(n,n));
    }
}
