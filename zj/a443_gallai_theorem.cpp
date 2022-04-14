#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(long long &a,long long &b){
    return a>b;
}
long long data[1000001];
int main(){
    long long n,i,j,l,r,m,flag;
    while(scanf("%lld",&n)==1&&n){
        for(i=1;i<=n;i++){
            scanf("%lld",data+i);
        }
        flag=0;
        sort(data+1,data+n+1,cmp);
        for(i=2;i<=n;i++){
            data[i]+=data[i-1];
        }
        if(data[n]%2)flag=1;
        for(i=1;!flag&&i<=n;i++){
            l=i+1,r=n+1;
            j=i;
            while(l<=n&&l!=r){
                m=(l+r)/2;
                if(data[m]-data[m-1]>i){
                    j=m;
                    l=m+1;
                }else if(data[m]-data[m-1]<i){
                    r=m;
                }else{
                    j=m;
                    break;
                }
            }
            if(data[i]>i*(j-1)+data[n]-data[j]){//i*(i-1)+i*(j-i)+data[n]-data[j]
                flag=1;
            }
        }
        if(flag){
            printf("Not possible\n");
        }else{
            printf("Possible\n");
        }
    }
}
