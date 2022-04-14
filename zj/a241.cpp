#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int m,n,sum;
    while(scanf("%d",&m)==1){
        while(m-->0){
            scanf("%d",&n);
            sum=0;
            for(int i=1,j=12,tmp=244140625;i<=n;i<<=1){
                while(i*tmp>n){
                    tmp/=5;
                    j--;
                }
                sum+=j+1;
            }
            printf("%d\n",sum-1);
        }
    }
}