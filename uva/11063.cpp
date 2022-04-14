#include <iostream>
#include <cstdio>
using namespace std;
int data[100];
bool res[20001];
int main(){
    int t=0,n,i,j,ans;
    while(scanf("%d",&n)==1){
        ans=1;
        for(i=0;i<n;i++){
            scanf("%d",data+i);
            if(data[i]<=0)ans=0;
            if(i>0&&data[i-1]>=data[i])ans=0;
        }
        for(i=0;i<20001;i++)res[i]=0;
        for(i=0;i<n;i++){
            for(j=i;j<n&&ans;j++){
                if(res[data[i]+data[j]]){
                    ans=0;
                }else{
                    res[data[i]+data[j]]=1;
                }
            }
        }
        if(ans){
            printf("Case #%d: It is a B2-Sequence.\n\n",++t);
        }else{
            printf("Case #%d: It is not a B2-Sequence.\n\n",++t);
        }
    }
}
