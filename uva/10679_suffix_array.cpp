#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

char str[100001];
int n;
struct node{
    int i,v;
    bool operator<(node& o){
        if(v!=o.v)return v<o.v;
        return i>o.i;
    }
};
int rk[300000];
node sa[100001];
char sstr[1001];
int main(){
    int T,t,i,j,len,l,r,m,ret;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str);
        for(n=0;str[n];n++){
            sa[n].i=n;
            sa[n].v=str[n];
        }
        sort(sa,sa+n);
        for(i=1,rk[sa[0].i]=0;i<n;i++){
            rk[sa[i].i]=rk[sa[i-1].i]+(sa[i].v!=sa[i-1].v);
        }
        len=1;
        while(len<n){
            for(i=0;i<n;i++){
                j=sa[i].i;
                sa[i].v=rk[j]*n+rk[j+len];
            }
            sort(sa,sa+n);
            for(i=1,rk[sa[0].i]=0;i<n;i++){
                rk[sa[i].i]=rk[sa[i-1].i]+(sa[i].v!=sa[i-1].v);
            }
            len<<=1;
        }
        scanf("%d",&t);
        while(t--){
            scanf("%s",sstr);
            l=0,r=n;
            while(l<r){
                m=(l+r)>>1;
                for(i=sa[m].i,j=0,ret=-1;str[i]&&sstr[j];i++,j++){
                    if(str[i]!=sstr[j]){
                        ret=str[i]<sstr[j];
                    }
                }
                if(ret==1){
                    l=m+1;
                }else if(ret==0){
                    r=m;
                }else if(!sstr[j]){
                    break;
                }else{
                    l=m+1;
                }
            }
            if(l<r){
                printf("y\n");
            }else{
                printf("n\n");
            }
        }
    }
}
