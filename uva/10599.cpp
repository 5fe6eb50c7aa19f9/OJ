#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
    int r,c,route;
    node* source;
};
node data[10000];
node lis[200][10000];
int num[200];
int N,M;
void dfs(node *now){
    if(now->source)dfs(now->source);
    printf(" %d",(now->r-1)*M+now->c);
}
bool cmp(node &a,node &b){
    if(a.r!=b.r)return a.r<b.r;
    return a.c<b.c;
}
int main(){
    int Case=0,n,i,j,k,l,r,m,flag,retlength,retroute;
    while(scanf("%d %d",&N,&M)&&!(N==-1&&M==-1)){
        memset(num,0,sizeof(num));
        n=retlength=retroute=0;
        while(scanf("%d %d",&data[n].r,&data[n].c)&&data[n].r){
            n++;
        }
        sort(data,data+n,cmp);
        for(i=0;i<n;i++){
            if(retlength==0){
                lis[retlength][num[retlength]]=data[i];
                lis[retlength][num[retlength]].route=1;
                lis[retlength][num[retlength]].source=0;
                num[0]=retlength=1;
            }else{
                l=0,r=retlength,flag=0;
                while(l<r){
                    m=(l+r)>>1;
                    for(j=0,k=0;j<num[m];j++){
                        if(lis[m][j].c<=data[i].c)k++;
                    }
                    if(k!=0){
                        l=flag=m+1;
                    }else{
                        r=m;
                    }
                }
                lis[flag][num[flag]]=data[i];
                lis[flag][num[flag]].source=0;
                if(flag>0){
                    lis[flag][num[flag]].route=0;
                    for(j=0;j<num[flag-1];j++){
                        if(lis[flag-1][j].c<=data[i].c){
                            lis[flag][num[flag]].route+=lis[flag-1][j].route;
                            if(!lis[flag][num[flag]].source)lis[flag][num[flag]].source=&lis[flag-1][j];
                        }
                    }
                }else{
                    lis[flag][num[flag]].route=1;
                }
                num[flag]++;
                if(flag==retlength)retlength++;
            }
        }
        for(i=0;i<num[retlength-1];i++){
            retroute+=lis[retlength-1][i].route;
        }
        printf("CASE#%d: %d %d",++Case,retlength,retroute);
        dfs(&lis[retlength-1][0]);
        printf("\n");
    }
}
