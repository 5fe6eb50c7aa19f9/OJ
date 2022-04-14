#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define Max 1000001
#define STORE 5
int ANS[STORE];
int A,repeat;
int TMP[STORE];
bool prime[Max]={false};
void go(int data,int n,int lim){
    if(n==lim){
        if(data==0){
            if(n<A){
                for(int i=0;i<n;i++)ANS[i]=TMP[i];
                A=n;
                return;
            }
            long long tmp1=ANS[0];
            long long tmp2=TMP[0];
            for(int i=1;i<n;i++){
                tmp1*=ANS[i];
                tmp2*=TMP[i];
            }
            if(tmp2>tmp1){
                for(int i=0;i<n;i++)ANS[i]=TMP[i];
                A=n;
                repeat=0;
            }
            repeat++;
        }
        return;
    }
    for(long long i=data/(lim-n);i>=2;i--){
        if(lim-n==1&&prime[i])break;
        if(n>=1&&TMP[n-1]>i)break;
        if(repeat>1)break;
        if(!prime[i]){
            TMP[n]=i;
            go(data-i,n+1,lim);
        }
    }
}
int main(){
    for(long long i=2;i<Max;i++){
        if(!prime[i]){
            for(long long j=i*i;j<Max;j+=i)prime[j]=true;
        }
    }
    int data;
    while(cin>>data){
        if(data==0)break;
        A=0x7fffffff;
        repeat=0;
        for(int i=1;i<=100&&A==0x7fffffff;i++)go(data,0,i);
        printf("%d ",A);
        for(int i=0;i<A;i++)printf("%d ",ANS[i]);
        printf("\n");
    }
}
