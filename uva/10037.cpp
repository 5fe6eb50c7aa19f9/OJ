#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int data[1000];
int main(){
    int t,n,i,sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
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
        }else{
            sum+=data[0];
        }
        printf("%d\n",sum);
        for(i=n-1;i>=3;i-=2){
            if(data[0]+data[1]*2+data[i]<data[0]*2+data[i-1]+data[i]){
                printf("%d %d\n%d\n",data[0],data[1],data[0]);
                printf("%d %d\n%d\n",data[i-1],data[i],data[1]);
            }else{
                printf("%d %d\n%d\n",data[0],data[i-1],data[0]);
                printf("%d %d\n%d\n",data[0],data[i],data[0]);
            }
        }
        if(i==2){
            printf("%d %d\n%d\n",data[0],data[2],data[0]);
            printf("%d %d\n",data[0],data[1]);
        }else if(i==1){
            printf("%d %d\n",data[0],data[1]);
        }else{
            printf("%d\n",data[0]);
        }
        if(t!=0)printf("\n");
    }
}
