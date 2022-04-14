#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
string buff;
int data[100];
unsigned long long dp[1000001];
unsigned long long sep=100000000000000000;
int main(){
    unsigned long long i,j,n,ans[2],lim[2];
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
        ans[0]=ans[1]=lim[0]=lim[1]=0;
        for(i=0;i<=data[n-1];i++)dp[i]=0;
        for(i=1;i<n;i++){
            ans[0]+=lim[0],ans[1]+=lim[1];
            ans[1]+=ans[0]/sep;
            ans[0]%=sep;
            lim[0]<<=1,lim[1]<<=1;
            lim[1]+=lim[0]/sep;
            lim[0]%=sep;
            for(j=data[i]+data[n-1];j>data[i]*2;j--){
                if(j<=data[n-1]){
                    dp[j]+=dp[j-data[i]];
                }else{
                    lim[0]+=dp[j-data[i]];
                    lim[1]+=lim[0]/sep;
                    lim[0]%=sep;
                }
                ans[0]+=dp[j-data[i]];
                ans[1]+=ans[0]/sep;
                ans[0]%=sep;
            }
            for(j=data[i]*2;j>=data[i];j--){
                if(j<=data[n-1]){
                    dp[j]+=dp[j-data[i]];
                }else{
                    lim[0]+=dp[j-data[i]];
                    lim[1]+=lim[0]/sep;
                    lim[0]%=sep;
                }
            }
            for(j=0;j<i;j++){
                if(data[i]+data[j]<=data[n-1]){
                    dp[data[i]+data[j]]++;
                }else{
                    lim[0]++;
                    lim[1]+=lim[0]/sep;
                    lim[0]%=sep;
                }
            }
        }
        if(ans[1]){
            printf("%llu%017llu\n",ans[1],ans[0]);
        }else{
            printf("%llu\n",ans[0]);
        }
    }
}
