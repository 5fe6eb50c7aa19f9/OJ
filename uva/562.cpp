#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;

int main(){
    int t,i,j,n,sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        bitset<50000> bs=1;
        for(i=sum=0;i<n;i++){
            scanf("%d",&j);
            sum+=j;
            bs|=bs<<j;
        }
        for(i=sum/2;i>=0;i--){
            if(bs[i])break;
        }
        printf("%d\n",sum-i*2);
    }
}
