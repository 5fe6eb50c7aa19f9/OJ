#include <cstdio>
#include <iostream>
using namespace std;
long long dp[50001][10]={0};//
long long go(int n,int lim){
    if(dp[n][lim]!=0)return dp[n][lim];
    long long tmp=0;
    if(n>=1&&lim>=0)tmp+=go(n-1,0);
    if(n>=5&&lim>=1)tmp+=go(n-5,1);
    if(n>=10&&lim>=2)tmp+=go(n-10,2);
    if(n>=20&&lim>=3)tmp+=go(n-20,3);
    if(n>=50&&lim>=4)tmp+=go(n-50,4);
    if(n>=100&&lim>=5)tmp+=go(n-100,5);
    if(n>=200&&lim>=6)tmp+=go(n-200,6);
    if(n>=500&&lim>=7)tmp+=go(n-500,7);
    if(n>=1000&&lim>=8)tmp+=go(n-1000,8);
    if(n>=2000&&lim>=9)tmp+=go(n-2000,9);
    dp[n][lim]=tmp;
    return dp[n][lim];
}
int main(){
    string data;
    for(int i=0;i<50001;i++){
        for(int j=0;j<10;j++){
            dp[i][j]=0;
            if(i==0)dp[i][j]=1;
        }
    }
    while(getline(cin,data)){
        if(data=="0")break;
        int sum=0;
        for(int i=0;i<data.size();i++){
            if(data[i]==' ')continue;
            int tmp=0;
            for(int j=i;j<data.size()&&data[j]!=' ';j++){
                tmp*=10;
                tmp+=data[j]-'0';
                i=j;
            }
            sum+=tmp;
        }
        cout<<go(sum,9)-1<<endl;
    }
}
