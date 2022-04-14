#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int suffix[100000];
string T,P;
bool cmp(int a,int b){
    for(int i=a,j=b;i<T.size()&&j<T.size();i++,j++){
        if(T[i]!=T[j]){
            return T[i]<T[j];
        }
    }
    return a>b;
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
        suffix[i]=i;
    }
    sort(suffix,suffix+T.size(),cmp);
    int n;
    scanf("%d",&n);
    getline(cin,P);//prevent P from getting '\n'
    while(n-->0){
        getline(cin,P);
        printf("%d\n",ub(0,T.size())-lb(0,T.size())+1);//if not found:(-2)-(-1)+1=0
    }
}
