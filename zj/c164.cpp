#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
    int i,j,n,ans;
    while(scanf("%d",&n)==1){
        ans=0;
        for(i=1;;i++){
            if(n>=i){
                n-=i;
                ans+=i*i;
            }else{
                ans+=i*n;
                break;
            }
        }
        printf("%d\n",ans);
    }
}
