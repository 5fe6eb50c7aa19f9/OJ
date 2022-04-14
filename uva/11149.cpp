#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct matrix{
    int v[40][40];
};
int n;
matrix m,m1,m2,tmp;
matrix add(matrix a,matrix b){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a.v[i][j]+=b.v[i][j];
            a.v[i][j]%=10;
        }
    }
    return a;
}
matrix mul(matrix a,matrix b){
    int i,j,k;
    matrix ret;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ret.v[i][j]=0;
            for(k=0;k<n;k++){
                ret.v[i][j]+=a.v[i][k]*b.v[k][j];
            }
            ret.v[i][j]%=10;
        }
    }
    return ret;
}
void DC(int k){
    if(k==1){
        m1=m2=m;
        return;
    }
    DC(k/2);
    if(k&1){
        tmp=add(m1,mul(m,m2));
    }else{
        tmp=m1;
    }
    m1=add(m1,mul(tmp,m2));
    m2=mul(m2,m2);
    if(k&1){
        m2=mul(m2,m);
    }
}
int main(){
    int t=0,k,i,j;
    while(scanf("%d %d",&n,&k)==2&&n){
        if(t++)printf("\n");
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&m.v[i][j]);
                m.v[i][j]%=10;
            }
        }
        DC(k);
        for(i=0;i<n;i++){
            printf("%d",m1.v[i][0]);
            for(j=1;j<n;j++){
                printf(" %d",m1.v[i][j]);
            }
            printf("\n");
        }
    }
}
