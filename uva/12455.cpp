#include <iostream>
#include <cstdio>
using namespace std;
int data[20];
int num;
bool go(int i,int n){
    if(i==num||n<=0){
        if(n==0)return 1;
        else return 0;
    }
    bool res=0;
    res+=go(i+1,n);
    if(res)return res;
    res+=go(i+1,n-data[i]);
    return res;
}
int main(){
    int t,i,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&num);
        for(i=0;i<num;i++)scanf("%d",data+i);
        if(go(0,n)==0){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
}
