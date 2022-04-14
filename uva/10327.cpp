#include <iostream>
#include <cstdio>
using namespace std;

int data[1000];
int main(){
    int n,i,j,ans;
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++)scanf("%d",data+i);
        ans=0;
        for(i=0;i<n;i++){
            for(j=n-1;j>=0;j--){
                if(data[j]<data[j-1]){
                    swap(data[j],data[j-1]);
                    ans++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n",ans);
    }
}
