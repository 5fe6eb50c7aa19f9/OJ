#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int data[500];
int main(){
    int t,n,i,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",data+i);
        }
        sort(data,data+n);
        for(i=ans=0;i<n;i++){
            ans+=abs(data[i]-data[n/2]);//data[n/2] have same data number at its left and right
        }
        printf("%d\n",ans);
    }
}
