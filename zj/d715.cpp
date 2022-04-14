#include <cstdio>
#include <iostream>
using namespace std;
int rule[]={1,1,1,3,3,3,3,1,1,9,9,9,9,7,7,7,7,9,9,1};
unsigned long long two;
int ans;
void clc(int n,bool flag){
    if(n<=1)return;
    ans=ans*rule[n%20]%10;
    if(flag){
        clc(n/2,1);
    }
    clc(n/5,0);
}
int main(){
    int n,i;
    while(scanf("%d",&n)==1){
        two=0;
        ans=1;
        clc(n,1);
        for(i=n;i>0;i/=2)two+=i/2;
        for(i=n;i>0;i/=5)two-=i/5;
        two%=4;
        if(n>1&&two==0){
            ans*=6;
        }else if(two==1){
            ans*=2;
        }else if(two==2){
            ans*=4;
        }else if(two==3){
            ans*=8;
        }
        printf("%d\n",ans%10);
    }
}
