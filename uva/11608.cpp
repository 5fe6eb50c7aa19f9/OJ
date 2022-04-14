#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int arr1[12];
int arr2[12];
int main(){
    int i,j,n,t=0;
    while(scanf("%d",&n)&&n>=0){
        printf("Case %d:\n",++t);
        for(i=0;i<12;i++)scanf("%d",arr1+i);
        for(i=0;i<12;i++)scanf("%d",arr2+i);
        for(i=0;i<12;i++){
            if(n<arr2[i]){
                printf("No problem. :(\n");
            }else{
                printf("No problem! :D\n");
                n-=arr2[i];
            }
            n+=arr1[i];
        }
    }
}
