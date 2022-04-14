#include <cstdio>
#include <iostream>
using namespace std;

int sieve[(5000>>5)+1];
int prime[1000];
int num;
int main(){
    int t,T,m,n,i,j,ans,tmp1,tmp2;
    prime[num++]=2;
    for(i=3;i<5000;i+=2){
        if((sieve[i>>5]>>(i&31))%2==0){
            prime[num++]=i;
            for(j=i*i;j<5000;j+=i){
                sieve[j>>5]|=1<<(j&31);
            }
        }
    }
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d %d",&m,&n);
        ans=0x7fffffff;
        for(i=0;prime[i]*prime[i]<=m;i++){
            if(m%prime[i]==0){
                tmp1=tmp2=0;
                while(m%prime[i]==0){
                    tmp1++;
                    m/=prime[i];
                }
                for(j=prime[i];j<=n;j*=prime[i]){
                    tmp2+=n/j;
                }
                ans=min(ans,tmp2/tmp1);
            }
        }
        if(m!=1){
            tmp2=0;
            for(j=m;j<=n;j*=m){
                tmp2+=n/j;
            }
            ans=min(ans,tmp2);
        }
        printf("Case %d:\n",t);
        if(ans==0){
            printf("Impossible to divide\n");
        }else{
            printf("%d\n",ans);
        }
    }
}
