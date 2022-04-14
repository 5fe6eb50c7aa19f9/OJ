#include <iostream>
#include <cstdio>
using namespace std;
int bs(int* data,int a,int b,int target){
    int avg=(a+b)>>1;
    if(data[avg]==target){
        return avg+1;
    }else if(data[avg]<target&&avg+1<=b){
        return bs(data,avg+1,b,target);
    }else if(avg-1>=a){
        return bs(data,a,avg-1,target);
    }
    return 0;
}
int main(){
    int n,k;
    while(scanf("%d %d",&n,&k)==2){
        int data[n];
        int target[k];
        int ans[k]={0};
        for(int i=0;i<n;i++)scanf("%d",&data[i]);
        for(int i=0;i<k;i++)scanf("%d",&target[i]);
        for(int i=0;i<k;i++){
            ans[i]=bs(data,0,n-1,target[i]);
        }
        for(int i=0;i<k;i++)printf("%d\n",ans[i]);
    }
}
