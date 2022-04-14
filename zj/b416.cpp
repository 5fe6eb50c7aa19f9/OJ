#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int sep;
struct Prob{
    int i,ql,qr,a,b;
    bool operator<(Prob &b){
        if(ql/sep!=b.ql/sep)return ql<b.ql;
        return qr<b.qr;
    }
};
int data[100000];
int divsep[100001];
int cnt[100001];
int num[400];
Prob prob[1000000];
int ans[1000000];
inline void add(int i){
    cnt[data[i]]++;
    num[divsep[data[i]]]++;
}
inline void sub(int i){
    cnt[data[i]]--;
    num[divsep[data[i]]]--;
}
int query(int a,int b){
    int ret=0;
    for(int i=divsep[a]+1;i<divsep[b];i++){
        ret+=num[i];
    }
    if(divsep[a]!=divsep[b]){
        for(int i=a;divsep[i]==divsep[a];i++){
            ret+=cnt[i];
        }
        for(int i=b;divsep[i]==divsep[b];i--){
            ret+=cnt[i];
        }
    }else{
        for(int i=a;i<=b;i++){
            ret+=cnt[i];
        }
    }
    return ret;
}
int main(){
    int n,m,i,nowL,nowR;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",data+i);
    }
    for(i=0;i<m;i++){
        prob[i].i=i;
        scanf("%d %d %d %d",&prob[i].ql,&prob[i].qr,&prob[i].a,&prob[i].b);
        prob[i].ql--;
    }
    sep=sqrt(n);
    for(i=0;i<=n;i++){
        divsep[i]=i/sep;
    }
    sort(prob,prob+m);
    nowL=0,nowR=1;
    cnt[data[0]]++;
    num[divsep[data[0]]]++;
    for(i=0;i<m;i++){
        while(nowR<prob[i].qr)add(nowR++);
        while(nowR>prob[i].qr)sub(--nowR);
        while(nowL<prob[i].ql)sub(nowL++);
        while(nowL>prob[i].ql)add(--nowL);
        ans[prob[i].i]=query(prob[i].a,prob[i].b);
    }
    for(i=0;i<m;i++){
        printf("%d\n",ans[i]);
    }
}
