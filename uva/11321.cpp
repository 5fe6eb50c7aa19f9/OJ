#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m;
struct node{
    int v;
    bool operator<(node& o){
        if(v%m!=o.v%m)return v%m<o.v%m;
        if((v%2)*(v%2)!=(o.v%2)*(o.v%2))return (v%2)*(v%2)>(o.v%2)*(o.v%2);
        if(v%2)return v>o.v;
        return v<o.v;
    }
};
node data[10000];
int main(){
    int i,j;
    while(1){
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d",&data[i].v);
        }
        printf("%d %d\n",n,m);
        if(n==0&&m==0)break;
        sort(data,data+n);
        for(i=0;i<n;i++){
            printf("%d\n",data[i].v);
        }
    }
}
