#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int data[100000];
int stk[100000];
int main(){
    int t=0,n,i,j,k;
    while(scanf("%d",&n)&&n){
        while(scanf("%d",data)&&data[0]){
            for(i=1;i<n;i++)scanf("%d",data+i);
            for(i=0,j=1,k=0;i<n;i++){
                if(data[i]==j){
                    j++;
                }else if(k!=0&&data[i]==stk[k-1]){
                    k--;
                }else{
                    if(j>n)break;
                    stk[k++]=j++;
                    i--;
                }
            }
            if(i!=n){
                printf("No\n");
            }else{
                printf("Yes\n");
            }
        }
        printf("\n");
    }
}
