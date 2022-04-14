#include <cstdio>
#include <iostream>
using namespace std;
long long data[1000];
int main(){
    int c,i,j,n,avg,num;
    scanf("%d",&c);
    while(c-->0){
        scanf("%d",&n);
        avg=num=0;
        for(i=0;i<n;i++){
            scanf("%d",&data[i]);
            data[i]*=n;
            avg+=data[i];
        }
        avg/=n;
        for(i=0;i<n;i++){
            if(data[i]>avg)num++;
        }
        printf("%.3f%%\n",(double)num*100/n);
    }
}
