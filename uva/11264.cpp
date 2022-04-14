#include <cstdio>
#include <iostream>
using namespace std;
int data[1000];
int main(){
    int t,n,i,ans;
    long long sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",data+i);
        }
        sum=data[0];
        ans=1;
        for(i=1;i<n;i++){
            if(sum+data[i]<data[i+1]||(i+1==n&&sum<data[i])){
                sum+=data[i];
                ans++;
            }
        }
        printf("%d\n",ans);
    }
}
