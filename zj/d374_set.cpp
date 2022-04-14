#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int sieve[50000];
unsigned long long prime[5133];
int pnum;
int factor[1000][2];
int fnum;
set<int> ans;
set<int>::iterator it;
unsigned long long n,a,b;

void brute(int k){
    unsigned long long i,j;
    if(k==fnum){
        b=n/a;
        if(a>=b){
            i=1,j=(a-2)/b;
        }else{
            i=(b+2)/a,j=1;
        }
        while(i*j<=n){
            if(a*i-b*j==2){
                ans.insert(a*i-1);
            }
            if(a>=b){
                i++;
                j=(a*i-2)/b;
            }else{
                j++;
                i=(b*j+2)/a;
            }
        }
        return;
    }
    for(i=0,j=1;i<=factor[k][1];i++,j*=factor[k][0]){
        a*=j;
        brute(k+1);
        a/=j;
    }
    return;
}
int main(){
    unsigned long long i,j,tmp;
    prime[pnum++]=2;
    for(i=3;i<50000;i+=2){
        if((sieve[i>>5]>>(i&31))%2==0){
            prime[pnum++]=i;
            for(j=i*i;j<50000;j+=i){
                sieve[j>>5]|=1<<(j&31);
            }
        }
    }
    while(scanf("%llu",&n)==1){
        if(n==1){
            printf("0\n");
            continue;
        }
        for(i=0,fnum=0,tmp=n;prime[i]*prime[i]<=tmp;i++){
            if(tmp%prime[i]==0){
                factor[fnum][0]=prime[i];
                factor[fnum][1]=0;
                while(tmp%prime[i]==0){
                    factor[fnum][1]++;
                    tmp/=prime[i];
                }
                fnum++;
            }
        }
        if(tmp!=1){
            factor[fnum][0]=tmp;
            factor[fnum][1]=1;
            fnum++;
        }
        a=1;
        brute(0);
        ans.insert(1);
        ans.insert(n-1);
        printf("%d\n",ans.size());
        for(it=ans.begin();it!=ans.end();it++){
            printf("%d\n",*it);
        }
        ans.clear();
    }
}
