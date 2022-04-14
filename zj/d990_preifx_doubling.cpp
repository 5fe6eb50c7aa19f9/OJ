#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int suffix[100000];
int w[100000];
int tmp[100000];
int d;
int* rk=suffix;
string T,P;
bool cmp(int a,int b){
    if(w[a]!=w[b]){
        return w[a]<w[b];
    }
    int wa=(a+d<T.size()?w[a+d]:-1);
    int wb=(b+d<T.size()?w[b+d]:-1);
    return wa<wb;
}
bool cmp2(int a,int b){
    if(w[a]!=w[b]){
        return 1;
    }
    int wa=a+d<T.size()?w[a+d]:-1;
    int wb=b+d<T.size()?w[b+d]:-1;
    return wa==wb?0:1;
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
int main(){
    getline(cin,T);
    for(int i=0;i<T.size();i++){
        rk[i]=i;
        w[i]=T[i];
    }
    for(d=1;d<T.size();d<<=1){
        sort(rk,rk+T.size(),cmp);
        for(int j=0,num=0;j<T.size();j++){
            if(j+1<T.size()&&cmp2(rk[j],rk[j+1])){
                tmp[rk[j]]=num++;
            }else{
                tmp[rk[j]]=num;
            }
        }
        for(int j=0;j<T.size();j++)w[j]=tmp[j];
    }
    int n;
    scanf("%d",&n);
    getline(cin,P);//prevent P from getting '\n'
    while(n-->0){
        getline(cin,P);
        printf("%d\n",ub(0,T.size())-lb(0,T.size())+1);//if not found:(-2)-(-1)+1=0
    }
}
