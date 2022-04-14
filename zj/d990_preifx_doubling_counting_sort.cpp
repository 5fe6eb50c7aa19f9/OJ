#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int suffix[100000];
int tmp[100000];
int c[100000];
int rk[100000];
int newrk[100000];
string T,P;

int ub(int l,int r);
int lb(int l,int r);

int main(){
    int i,j,num,A=128;
    getline(cin,T);
    for(int i=0;i<T.size();i++){
        rk[i]=T[i];
        c[rk[i]]++;
    }
    for(i=1;i<A;i++)c[i]+=c[i-1];
    for(i=T.size()-1;i>=0;i--)suffix[--c[T[i]]]=i;

    for(int d=1;d<T.size();d<<=1){
        for(i=0;i<A;i++)c[i]=0;
        for(i=0;i<T.size();i++)c[rk[i]]++;
        for(i=1;i<A;i++)c[i]+=c[i-1];
        num=0;
        for(i=T.size()-d;i<T.size();i++)tmp[num++]=i;//sa2
        for(i=0;i<T.size();i++){
            if(suffix[i]>=d){
                tmp[num++]=suffix[i]-d;
            }
        }
        for(i=T.size()-1;i>=0;i--)suffix[--c[rk[tmp[i]]]]=tmp[i];
        for(i=0,num=0;i<T.size();i++){
            if(i>0&&!(rk[suffix[i]]==rk[suffix[i-1]]&&suffix[i-1]+d<T.size()&&rk[suffix[i]+d]==rk[suffix[i-1]+d]))num++;
            newrk[suffix[i]]=num;
        }
        for(i=0;i<T.size();i++)rk[i]=newrk[i];
        A=num+1;
    }
    int n;
    scanf("%d",&n);
    getline(cin,P);//prevent P from getting '\n'
    while(n-->0){
        getline(cin,P);
        printf("%d\n",ub(0,T.size())-lb(0,T.size())+1);//[lb,ub]:closed range,if not found:(-2)-(-1)+1=0
    }
}
int lb(int l,int r){//lower bound
    if(l>r-1)return -1;
    int m=(l+r)>>1;
    for(int i=suffix[m],j=0;i<T.size();i++,j++){
        if(T[i]!=P[j]){
            if(T[i]<P[j]){
                return lb(m+1,r);
            }else{
                return lb(l,m);
            }
        }
        if(j+1==P.size()){
            int tmp=lb(l,m);
            if(tmp!=-1){
                return tmp;
            }else{
                return m;
            }
        }
    }
    return lb(m+1,r);
}
int ub(int l,int r){//upper bound
    if(l>r-1)return -2;
    int m=(l+r)>>1;
    for(int i=suffix[m],j=0;i<T.size();i++,j++){
        if(T[i]!=P[j]){
            if(T[i]<P[j]){
                return ub(m+1,r);
            }else{
                return ub(l,m);
            }
        }
        if(j+1==P.size()){
            int tmp=ub(m+1,r);
            if(tmp!=-2){
                return tmp;
            }else{
                return m;
            }
        }
    }
    return ub(m+1,r);
}
