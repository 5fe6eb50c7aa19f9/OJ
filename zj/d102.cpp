#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

string buff;
int data[100];
int dp[1000001];
int main(){
    int i,j,n,ans,lim;
    while(getline(cin,buff)&&buff!="0"){
        buff+=" ";
        for(i=j=n=0;i<buff.size();i++){
            if(buff[i]==' '){
                if(buff[i-1]>='0'&&buff[i-1]<='9')data[n++]=j;
                j=0;
            }else if(buff[i]>='0'&&buff[i]<='9'){
                j=j*10+buff[i]-'0';
            }
        }
        sort(data,data+n);
        ans=lim=0;
        for(i=0;i<=data[n-1];i++)dp[i]=0;
        for(i=1;i<n;i++){
            ans+=lim;
            lim<<=1;
            for(j=data[i]+data[n-1];j>data[i]*2;j--){
                if(j<=data[n-1]){
                    dp[j]+=dp[j-data[i]];
                }else{
                    lim+=dp[j-data[i]];
                }
                ans+=dp[j-data[i]];
            }
            for(j=data[i]*2;j>=data[i];j--){
                if(j<=data[n-1]){
                    dp[j]+=dp[j-data[i]];
                }else{
                    lim+=dp[j-data[i]];
                }
            }
            for(j=0;j<i;j++){
                if(data[i]+data[j]<=data[n-1]){
                    dp[data[i]+data[j]]++;
                }else{
                    lim++;
                }
            }
        }
        printf("%d\n",ans);
    }
}
