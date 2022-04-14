#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

bool read[2001];
int main(){
    int n,i,j;
    while(scanf("%d",&n)==1){
        memset(read,0,sizeof(read));
        for(i=0;i<n;i++){
            scanf("%d",&j);
            read[j]=1;
        }
        for(i=1;i<=2000;i++){
            if(!read[i]){
                printf("%d\n",i);
                break;
            }
        }
    }
}
