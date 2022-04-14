#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int cnt[1000];
int main(){
    int n,i,j,k,ans;
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++)cnt[i]=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&k);
                if(k==1){
                    cnt[i]++;
                }
            }
        }
        for(i=0,ans=0;i<n;i++){
            ans+=cnt[i]*(n-1-cnt[i]);
        }
        ans=n*(n-1)*(n-2)/6-ans/2;
        printf("%d\n",ans);
    }
}
