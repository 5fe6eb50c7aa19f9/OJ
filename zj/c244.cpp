#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char buf[10000000];
int main(){
    long long t,T,N,m1,m2,v1,v2,i,j,tmp,ans,b=0;
    scanf("%lld\n",&T);
    scanf("%[^eof]",buf);
    for(t=1;t<=T;t++){
        for(j=0;buf[b]>='0'&&buf[b]<='9';b++){
            j=(j<<3)+(j<<1)+buf[b]-'0';
        }
        N=j;
        b++;
        for(j=0;buf[b]>='0'&&buf[b]<='9';b++){
            j=(j<<3)+(j<<1)+buf[b]-'0';
        }
        m1=j;
        b++;
        for(j=0;buf[b]>='0'&&buf[b]<='9';b++){
            j=(j<<3)+(j<<1)+buf[b]-'0';
        }
        v1=j;
        b++;
        for(j=0;buf[b]>='0'&&buf[b]<='9';b++){
            j=(j<<3)+(j<<1)+buf[b]-'0';
        }
        m2=j;
        b++;
        for(j=0;buf[b]>='0'&&buf[b]<='9';b++){
            j=(j<<3)+(j<<1)+buf[b]-'0';
        }
        v2=j;
        b++;
        if(m1<m2){
            swap(m1,m2);
            swap(v1,v2);
        }
        ans=0;
        if(N/m1<20){
            for(i=N/m1;i>=0;i--){
                j=(N-m1*i)/m2;
                ans=max(ans,v1*i+v2*j);
            }
        }else{
            if(v1*m2<v2*m1){// c/p
                swap(m1,m2);
                swap(v1,v2);
            }
            for(i=N/m1;i>=0;i--){
                j=(N-m1*i)/m2;
                tmp=v1*i+v2*j;
                ans=max(ans,tmp);
                if(v2*(N-m1*i-m2*j)+tmp*m2<=ans*m2)break;
            }
        }
        printf("Case #%lld: %lld\n",t,ans);
    }
}
