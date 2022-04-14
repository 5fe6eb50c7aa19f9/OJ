#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int a,b,loc;
};
bool cmp(node& i,node& j){
    return (i.loc)<(j.loc);
}
vector<node> data(100000);
int n;
int main(){
    int m,tmp,ans,i,j,a,b,l,r;
    while(scanf("%d",&m)==1){
        while(m-->0){
            scanf("%d",&n);
            l=0,r=0;
            for(i=0;i<n;i++){
                scanf("%d %d",&a,&b);
                data[i].a=a,data[i].b=b,data[i].loc=b/a;
                r+=a;
            }
            sort(data.begin(),data.begin()+n,cmp);
            for(i=1,tmp=0;i<n;i++){
                tmp+=(data[i].loc-data[0].loc)*data[i].a;
            }
            ans=tmp;
            for(i=1,l=data[0].a,r=r*-1+data[0].a;i<n;i++){
                j=data[i].loc-data[i-1].loc;
                tmp+=j*(l+r);
                if(ans>tmp)ans=tmp;
                l+=data[i].a;
                r+=data[i].a;
            }
            printf("%d\n",ans);
        }
    }
}
