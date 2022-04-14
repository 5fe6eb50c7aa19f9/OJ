#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int ans[1000000];
int l,r;
int main(){
    int n,i,b,e,tmp;
    long long m;
    while(scanf("%d %lld",&n,&m)==2){
        l=0;
        r=n-1;
        for(b=1,e=n;m>=0;){
            if(m==0){
                for(i=b;i<=e;i++){
                    ans[l++]=i;
                }
                break;
            }
            tmp=e;
            while(m-(tmp-b)<0){
                tmp--;
            }
            for(i=e;i>=tmp+1;i--)ans[r--]=i;
            ans[r--]=b;
            m=m-(tmp-b);
            b=b+1;
            e=tmp;
        }
        for(i=0;i<n;i++)printf("%d ",ans[i]);
        printf("\n");
    }
}
