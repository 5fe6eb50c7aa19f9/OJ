#include <cstdio>
#include <cstring>
#include <cmath>
#include <complex>
using namespace std;

#define MAXN 600000
const double pi=3.14159265359;
typedef complex<double> C;

char s1[MAXN],s2[MAXN];
C a[MAXN],b[MAXN],c[MAXN],tmp[MAXN];
int ans[MAXN];
void FFT(C* x,int len,int mode){
    if(len==1)return;
    int i,j;
    for(i=0,j=0;j<len;i++,j+=2)tmp[i]=x[j];
    for(j=1;j<len;i++,j+=2)tmp[i]=x[j];
    for(i=0;i<len;i++)x[i]=tmp[i];
    FFT(x,len/2,mode);
    FFT(x+len/2,len/2,mode);
    C w(cos(2.0*pi*mode/len),sin(2.0*pi*mode/len)),wn(1.0);
    for(i=0;i<len/2;i++){
        tmp[i]=x[i]+wn*x[i+len/2];
        tmp[i+len/2]=x[i]-wn*x[i+len/2];
        wn*=w;
    }
    for(i=0;i<len;i++){
        x[i]=tmp[i];
    }
}
int main(){
    int i,j,alen,blen,clen;
    while(scanf("%s %s",s1,s2)==2){
        alen=strlen(s1);
        blen=strlen(s2);
        clen=1<<(__lg(alen+blen));
        if(clen<alen+blen)clen<<=1;
        for(i=0;i<clen;i++)a[i]=i<alen?C(s1[alen-1-i]-'0'):C(0);
        for(i=0;i<clen;i++)b[i]=i<blen?C(s2[blen-1-i]-'0'):C(0);
        clen>>=1;
        for(i=0;i<clen;i++){
            a[i]=a[i*2].real()+a[i*2+1].real()*10.0;
            b[i]=b[i*2].real()+b[i*2+1].real()*10.0;
        }
        FFT(a,clen,1);
        FFT(b,clen,1);
        for(i=0;i<clen;i++)c[i]=a[i]*b[i];
        FFT(c,clen,-1);
        for(i=0;i<clen;i++)ans[i]=(int)(c[i].real()/clen+0.5);
        for(i=1;i<clen;i++){
            ans[i]+=ans[i-1]/100;
            ans[i-1]%=100;
        }
        while(ans[--i]==0&&i!=0);
        printf("%d",ans[i--]);
        while(i>=0)printf("%02d",ans[i--]);
        printf("\n");
    }
    return 0;
}
