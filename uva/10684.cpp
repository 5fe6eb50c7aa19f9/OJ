#include <iostream>
#include <cstdio>
using namespace std;

int data[1000];
int main(){
    int n,i,j,tmp,ans;
    while(scanf("%d",&n)&&n){
        for(i=tmp=ans=0;i<n;i++){
            scanf("%d",&j);
            tmp+=j;
            ans=max(ans,tmp);
            if(tmp<0)tmp=0;
        }
        if(ans>0){
            printf("The maximum winning streak is %d.\n",ans);
        }else{
            printf("Losing streak.\n");
        }
    }
}
