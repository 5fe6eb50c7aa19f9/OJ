#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int data[30000];
int main(){
    int n,w,ans=0,i,j;
    scanf("%d %d",&w,&n);
    for(i=0;i<n;i++)scanf("%d",data+i);
    sort(data,data+n);
    for(i=0,j=n-1;i<=j;j--,ans++){
        if(i<j&&data[i]+data[j]<=w){
            i++;
        }
    }
    printf("%d\n",ans);
}
