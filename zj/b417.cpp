#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct Quest{
    int i,l,r;
};
int sep;
int data[100000];
Quest quest[1000000];
int ans[1000000][2];
char buff[10000000];
int cnt[1000000];
int num[1000000];
int l,r,biggest;
bool cmp(Quest &a,Quest &b){
    if(a.l/sep!=b.l/sep)return a.l<b.l;
    return a.r<b.r;
}
inline void add(int i){
    num[cnt[data[i]]]--;
    cnt[data[i]]++;
    num[cnt[data[i]]]++;
    biggest=max(biggest,cnt[data[i]]);
}
inline void sub(int i){
    num[cnt[data[i]]]--;
    cnt[data[i]]--;
    num[cnt[data[i]]]++;
    if(!num[biggest])biggest--;
}
int main(){
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    sep=sqrt(n);
    for(i=0;i<n;i++)scanf("%d",data+i);
    scanf("%*c%[^eof]",buff);
    for(i=j=k=m=0;buff[i];i++){
        if(buff[i]>='0'&&buff[i]<='9'){
            j=(j<<3)+(j<<1)+buff[i]-'0';
        }else{
            if(k==0){
                quest[m].i=m;
                quest[m].l=j-1;
                k=1;
            }else{
                quest[m++].r=j;
                k=0;
            }
            j=0;
        }
    }
    sort(quest,quest+m,cmp);
    l=0;
    r=1;
    cnt[data[0]]=num[1]=biggest=1;
    for(i=0;i<m;i++){
        while(l<quest[i].l)sub(l++);
        while(l>quest[i].l)add(--l);
        while(r<quest[i].r)add(r++);
        while(r>quest[i].r)sub(--r);
        ans[quest[i].i][0]=biggest;
        ans[quest[i].i][1]=num[biggest];
    }
    for(i=0;i<m;i++){
        printf("%d %d\n",ans[i][0],ans[i][1]);
    }
}
