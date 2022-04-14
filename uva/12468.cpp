#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int a,b,ans;
    while(scanf("%d %d",&a,&b)&&!(a==-1&&b==-1)){
        if(a<b)swap(a,b);
        ans=min(a-b,b-(a-100));
        printf("%d\n",ans);
    }
}
