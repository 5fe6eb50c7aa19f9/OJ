#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
char data[10000010];
int main(){
    int n,m,i,j;
    while(scanf("%d %d",&n,&m)&&n+m){
        for(i=0,j=0;i<n;i++){
            scanf("%s",data+j);
            while(data[j])j++;
        }
        for(i=0;i<m;i++){
            scanf("%d",&j);
            printf("%c",data[j-1]);
        }
        printf("\n");
    }
}
