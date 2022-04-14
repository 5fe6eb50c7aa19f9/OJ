#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int index,day,money;
};
bool cmp(node &a,node &b){
    if(b.money*a.day!=a.money*b.day)return  b.money*a.day<a.money*b.day;
    return a.index<b.index;
}
node s[1000];
int main(){
    int t,n,i,j,k,acc;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=acc=0;i<n;i++){
            s[i].index=i;
            scanf("%d %d",&s[i].day,&s[i].money);
        }
        sort(s,s+n,cmp);
        for(i=0;i<n;i++){
            if(i>0)printf(" ");
            printf("%d",s[i].index+1);
        }
        printf("\n");
        if(t)printf("\n");
    }
}
