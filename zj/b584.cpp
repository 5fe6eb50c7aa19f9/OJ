#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int data[30];
int main(){
    int n,i,sum;
    while(scanf("%d",&n)==1&&n){
        for(i=0;i<n;i++){
            scanf("%d",data+i);
        }
        sort(data,data+n);
        sum=0;
        for(i=n-1;i>=3;i-=2){
            if(data[0]+data[1]*2+data[i]<data[0]*2+data[i-1]+data[i]){
                sum+=data[0]+data[1]*2+data[i];
            }else{
                sum+=data[0]*2+data[i-1]+data[i];
            }
        }
        if(i==2){
            sum+=data[0]+data[1]+data[2];
        }else if(i==1){
            sum+=data[1];
        }else if(i==0){
            sum+=data[0];
        }
        printf("%d\n",sum);
    }
}
