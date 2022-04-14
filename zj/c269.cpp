#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

double knapsack[1001];
int main(){
    int t,n,s,p,i,j,k,tmp;
    double v;
    while(scanf("%d %d",&n,&t)==2){
        memset(knapsack,0.0,sizeof(knapsack));
        for(i=0;i<n;i++){
            scanf("%d %lf %d",&s,&v,&p);
            if(p==2){
                for(j=t;j-s>=0;j--){
                    knapsack[j]=max(knapsack[j],knapsack[j-s]+v);
                }
            }else{
                tmp=s;
                for(k=1;tmp>0;k<<=1){
                    if(k>tmp)k=tmp;
                    tmp-=k;
                    for(j=t;j-k>=0;j--){
                        knapsack[j]=max(knapsack[j],knapsack[j-k]+v*k/s);
                    }
                }
            }
        }
        printf("%.0lf\n",knapsack[t]);
    }
}
