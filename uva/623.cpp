#include <cstdio>
#include <cstring>
unsigned long long ans[1001][3000];
int loc[1001];
void mlt(int n){
    loc[n]=loc[n-1];
    for(int i=0;i<loc[n];i++){
        ans[n][i]=ans[n-1][i]*n;
    }
    for(int i=0;i<loc[n];i++){
        ans[n][i+1]+=ans[n][i]/1000000000000000;
        ans[n][i]%=1000000000000000;
    }
    if(ans[n][loc[n]]>0)loc[n]++;
}
int main(){
    int n,i;
    ans[1][0]=loc[1]=1;
    for(i=2;i<=1000;i++){
        mlt(i);
    }
    while(scanf("%d",&n)==1){
        printf("%d!\n%llu",n,ans[n][loc[n]-1]);
        for(i=loc[n]-2;i>=0;i--){
            printf("%015llu",ans[n][i]);
        }
        printf("\n");
    }
}

