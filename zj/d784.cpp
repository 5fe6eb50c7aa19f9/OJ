#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int t,n,i,j,cur,tmp,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=0x80000000,cur=0;
        for(i=0;i<n;i++){
            scanf("%d",&tmp);
            cur+=tmp;
            ans=max(ans,cur);
            if(cur<0)cur=0;
        }
        printf("%d\n",ans);
    }
}
