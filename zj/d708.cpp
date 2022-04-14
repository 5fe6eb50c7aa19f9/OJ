#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int data[1000000];
int main(){
    int n,i,j,ans;
    scanf("%d",&n);
    for(i=ans=0;i<n-1;i++){
        scanf("%d",&j);
        ans^=j;
    }
    printf("%d\n",ans);
}
