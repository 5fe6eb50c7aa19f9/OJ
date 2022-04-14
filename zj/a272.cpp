#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
void mlt(int *a,int *b,int *c){
    int ans[4];
    ans[0]=(a[0]*b[0]+a[1]*b[2])%10007;
    ans[1]=(a[0]*b[1]+a[1]*b[3])%10007;
    ans[2]=(a[2]*b[0]+a[3]*b[2])%10007;
    ans[3]=(a[2]*b[1]+a[3]*b[3])%10007;
    for(int i=0;i<4;i++)c[i]=ans[i];
}
int pow(int n){
    int ans[4]={1,0,0,1};
    int a[4]={1,1,1,0};
    while(n>0){
        if(n&1)mlt(a,ans,ans);
        mlt(a,a,a);
        n>>=1;
    }
    return (ans[0]+ans[1])%10007;
}
int main(){
    int N;
    while(scanf("%d",&N)==1){
        printf("%d\n",pow(N-1));
    }
}
