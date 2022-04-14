#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    int n,i,j,num;
    long double ans;
    int data[50];
    while(scanf("%d",&n)==1&&n){
        for(i=0;i<n;i++)scanf("%d",data+i);
        num=0;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(gcd(data[i],data[j])==1){
                    num++;
                }
            }
        }
        if(num==0){
            printf("No estimate for this data set.\n");
            continue;
        }
        ans=3*n*(n-1);
        ans=sqrt(ans/num);
        printf("%.6llf\n",ans);
    }
}
