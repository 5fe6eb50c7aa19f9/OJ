#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double Qpow(double a,int b){
    if(b==0)return 1.0;
    double res=Qpow(a,b/2);
    res*=res;
    if(b&1)res*=a;
    return res;
}
int main(){
    int i,j,s,a,b;
    double w,l,tmp,ans;
    scanf("%d",&s);
    while(s>0){
        scanf("%d %lf %d",&a,&w,&b);
        ans=0.0;
        l=1-w;
        tmp=Qpow(l,b-1);
        while(tmp*w>0.0000000001){
            ans+=tmp*w;
            tmp*=Qpow(l,a);
        }
        printf("%.4f\n",ans);
        s--;
    }
}
