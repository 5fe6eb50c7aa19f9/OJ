#include <cstdio>
#include <iostream>
using namespace std;

int ans[21];//ans[i] is the rank of i
int rep[21];//rep[i] is the number of rank i
int lis[21];
int main(){
    int i,j,n,len,score,l,r,m,flag;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",ans+i);
    }
    while(scanf("%d",&j)==1){
        score=0;
        rep[j]=1;
        if(ans[1]==j)score++;
        for(i=2;i<=n;i++){
            scanf("%d",&j);
            rep[j]=i;
            if(ans[i]==j)score++;
        }
        for(i=1;i<=n;i++){
            rep[i]=ans[rep[i]];
        }
        len=0;
        for(i=1;i<=n;i++){
            if(len==0){
                lis[len++]=rep[i];
            }else{
                l=0,r=len;
                flag=0;
                while(l<r){
                    m=(l+r)/2;
                    if(lis[m]<rep[i]){
                        l=flag=m+1;
                    }else if(lis[m]>rep[i]){
                        r=m;
                    }else{
                        flag=m;
                        break;
                    }
                }
                if(flag==len)len++;
                lis[flag]=rep[i];
            }
        }
        printf("%d\n",max(score,len));
    }
}
