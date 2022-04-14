#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
    int i,j,r,c;
    int R,G,B,ret;
    while(scanf("%d %d",&c,&r)==2){
        printf("%d %d\n",c,r);
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                scanf("%d %d %d",&R,&G,&B);
                ret=(R+G+B)/3;
                if((R+G+B)%3==2)ret++;
                printf("%d %d %d ",ret,ret,ret);
            }
            printf("\n");
        }
    }
}
