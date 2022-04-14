#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int data[100000];
int main(){
    int n,q,k,i,j;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++)scanf("%d",data+i);
    sort(data,data+n);
    while(q--){
        scanf("%d",&k);
        for(i=0,j=1;;){
            if(data[j]-data[i]>k){
                i++;
            }else if(data[j]-data[i]<k){
                j++;
            }else{
                printf("YES\n");
                break;
            }
            if(j==n){
                printf("NO\n");
                break;
            }
        }
    }
}
