#include <cstdio>
#include <iostream>
using namespace std;
int dp[2][101][101];
int main(){
    bool now=0;
    string a,b,c;
    cin>>a>>b>>c;
    for(int i=1;i<=a.size();i++){
        now=!now;
        for(int j=1;j<=b.size();j++){
            for(int k=1;k<=c.size();k++){
                if(a[i-1]==b[j-1]&&a[i-1]==c[k-1]){
                    dp[now][j][k]=dp[!now][j-1][k-1]+1;
                }else{
                    dp[now][j][k]=dp[!now][j][k];
                    if(dp[now][j][k]<dp[now][j-1][k])dp[now][j][k]=dp[now][j-1][k];
                    if(dp[now][j][k]<dp[now][j][k-1])dp[now][j][k]=dp[now][j][k-1];
                    if(dp[now][j][k]<dp[!now][j-1][k])dp[now][j][k]=dp[!now][j-1][k];
                    if(dp[now][j][k]<dp[!now][j][k-1])dp[now][j][k]=dp[!now][j][k-1];
                    if(dp[now][j][k]<dp[now][j-1][k-1])dp[now][j][k]=dp[now][j-1][k-1];
                }
            }
        }
    }
    cout<<dp[now][b.size()][c.size()]<<endl;
}
