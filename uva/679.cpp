#include <iostream>
#include <cstdio>
using namespace std;
int clc(int d,int n){
    int ans=1;
    while(d>1){
        if(n&1){
            ans=ans*2+1;
        }else{
            ans=ans*2;
        }
        n/=2;
        d--;
    }
    return ans;
}
int main(){
    int t,i,d,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&d,&n);
        printf("%d\n",clc(d,n-1));
    }
}
