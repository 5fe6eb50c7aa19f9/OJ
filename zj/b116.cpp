#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;

bitset<1000000> bs;
int main(){
    int t,i,j,m,n,sum;
    while(scanf("%d %d",&m,&n)==2){
        while(m--){
            bs=1;
            for(i=sum=0;i<n;i++){
                scanf("%d",&j);
                bs|=bs<<j;
                sum+=j;
            }
            if(sum%2==0&&bs[sum/2]==1){
                printf("Yes \n");
            }else{
                printf("No \n");
            }
        }
    }
}
