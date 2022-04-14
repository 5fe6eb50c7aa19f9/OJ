#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int t,i,x,a,b,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&x,&a,&b);
        ans=10000;
        for(i=0;a*i<=x;i++){
            if((x-a*i)%b==0){
                ans=min(ans,i+(x-a*i)/b);
            }
        }
        if(ans==10000){
            printf("-1\n");
        }else{
            printf("%d\n",ans);
        }
    }
}
