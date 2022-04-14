#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
char data[1000005];
int main(){
    int t,n,i,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        data[0]=0;
        for(i=1;i<=n;i++){
            scanf("%d %d",&a,&b);
            data[i]=a+b;
        }
        for(i=i-1;i>=1;i--){
            data[i-1]+=data[i]/10;
            data[i]%=10;
        }
        i=1;
        if(data[0])i=0;
        for(;i<=n;i++)printf("%d",data[i]);
        printf("\n");
        if(t)printf("\n");
    }
}
