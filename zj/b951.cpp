#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int data[5000];
unsigned long long dp[2000];
unsigned long long delta[2000];
string tmp;
int main(){
    int n,i,j,sum,flag,l,r;
    long long k;
    while(getline(cin,tmp)){
        for(n=i=j=sum=0;i<tmp.size();i++){
            if(tmp[i]==' '){
                sum+=j;
                data[n++]=j;
                j=0;
            }else{
                j=j*10+tmp[i]-'0';
            }
        }
        sum+=j;
        data[n++]=j;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(i=0;i<n;i++){
            memset(delta,0,sizeof(delta));
            for(j=0,l=j+data[i],r=j+63+data[i];(l>>6)<=(sum>>7);j+=64,l+=64,r+=64){
                delta[l>>6]|=dp[j>>6]<<((r&63)+1);
                delta[r>>6]|=dp[j>>6]>>(63-(r&63));
            }
            for(j=0;(j>>6)<=(sum>>7);j+=64){
                dp[j>>6]|=delta[j>>6];
            }
        }
        k=-1;
        for(i=sum>>7,j=(sum/2)&63;j>=0;j--){
            if((dp[i]>>j)&1){
                k=(i<<6)+j;
                break;
            }
        }
        for(i=(sum>>7)-1;k==-1&&i>=0;i--){
            if(dp[i]){
                for(j=63;j>=0;j--){
                    if((dp[i]>>j)&1){
                        k=(i<<6)+j;
                        break;
                    }
                }
            }
        }
        printf("%lld\n",k*(sum-k));
    }
}
