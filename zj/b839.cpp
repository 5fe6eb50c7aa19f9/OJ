#include <cstdio>
#include <iostream>
using namespace std;
int dp[51][51];
int main(){
    int i,j,T,N,x,y,ans,sum;
    long long tmp=1;//if use 1<<50,it will be wrong
    scanf("%d",&T);
    while(T>0){
        T--;
        scanf("%d",&N);
        string data[N];
        for(i=0;i<N;i++)cin>>data[i];
        long long relation[N];
        for(i=0;i<N;i++)relation[i]=tmp<<i;
        for(i=0;i<N-1;i++){
            for(j=i+1;j<N;j++){
                //start to LCS
                for(x=1;x<=data[i].size();x++){
                    for(y=1;y<=data[j].size();y++){
                        if(data[i][x-1]==data[j][y-1]){
                            dp[x][y]=dp[x-1][y-1]+1;
                        }else{
                            dp[x][y]=max(dp[x-1][y],dp[x][y-1]);
                        }
                    }
                }
                if(dp[data[i].size()][data[j].size()]*2>=min(data[i].size(),data[j].size())){
                    relation[i]|=(tmp<<j);
                    relation[j]|=(tmp<<i);
                }
            }
        }
        ans=0;
        for(i=0;i<N;i++){
            for(j=i+1;j<N;j++){
                if((relation[i]>>j)&1){
                    relation[j]|=relation[i];
                }
            }
            sum=0;
            for(j=0;j<=50;j++){
                if((relation[i]>>j)&1)sum++;
            }
            if(sum>ans)ans=sum;
        }
        printf("%d\n",ans);
    }
}
