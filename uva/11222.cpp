#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int cnt[10001];
int who[10001];
void op(int i){
    for(int j=0;j<=10000;j++){
        if(cnt[j]==1&&who[j]==i){
            printf(" %d",j);
        }
    }
}
int main(){
    int T,t,n,i,j,k,flag;
    int tmp[3];
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        for(i=0;i<3;i++){
            scanf("%d",&n);
            while(n--){
                scanf("%d",&j);
                cnt[j]++;
                if(cnt[j]==1){
                    who[j]=i;
                }
            }
        }
        for(i=tmp[0]=tmp[1]=tmp[2]=flag=0;i<=10000;i++){
            if(cnt[i]==1){
                tmp[who[i]]++;
                flag=max(flag,tmp[who[i]]);
            }
        }
        printf("Case #%d:\n",t);
        for(i=0;i<3;i++){
            if(tmp[i]==flag){
                printf("%d %d",i+1,flag);
                op(i);
                printf("\n");
            }
        }
        for(i=0;i<=10000;i++)cnt[i]=0;
    }
}
