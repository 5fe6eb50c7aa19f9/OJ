#include <cstdio>
#include <iostream>
using namespace std;
string a,b;
int dp[31][31];
char prv[31][31];
unsigned int numLCS;
void tvl(int i,int j){
    if(i==0||j==0){
        numLCS++;
        return;
    }
    switch(prv[i][j]){
        case 1:
            tvl(i-1,j-1);
            break;
        case 2:
            tvl(i-1,j);
            break;
        case 3:
            tvl(i,j-1);
            break;
        case 4:
            tvl(i-1,j);
            tvl(i,j-1);
            break;
    }
}
int main(){
    int T,i,j,del;
    for(i=1;i<31;i++)prv[i][0]=2;
    for(j=1;j<31;j++)prv[0][j]=3;
    scanf("%d",&T);
    getline(cin,a);
    for(int n=1;n<=T;n++){//may exist empty data
        getline(cin,a);
        getline(cin,b);
        for(i=1;i<=a.size();i++){
            for(j=1;j<=b.size();j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    prv[i][j]=1;
                }else{
                    dp[i][j]=dp[i-1][j];
                    prv[i][j]=2;
                    if(dp[i][j]<dp[i][j-1]){
                        dp[i][j]=dp[i][j-1];
                        prv[i][j]=3;
                    }else if(dp[i][j]==dp[i][j-1]){
                        prv[i][j]=4;
                    }
                }
            }
        }
        numLCS=0;
        tvl(a.size(),b.size());
        printf("Case #%d: %d %d\n",n,a.size()+b.size()-dp[a.size()][b.size()],numLCS);
    }
}
