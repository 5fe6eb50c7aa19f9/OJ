#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int a,int b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
struct Tri{
    int a,b,c;
};
Tri tri[200000];
int tot;
int cnt1[200000];
int cnt2[1000001];
int main(){
    int i,j,k,a,b,c,n;
    for(i=2;i*i<1000000;i++){
        for(j=1;j<i&&i*i+j*j<=1000000;j++){
            if(gcd(i,j)!=1||i%2==j%2)continue;
            a=i*i-j*j;
            b=i*j*2;
            c=i*i+j*j;
            if(c<b)swap(c,b);
            if(b<a)swap(b,a);
            if(c>1000000)continue;
            tri[tot].a=a,tri[tot].b=b,tri[tot].c=c;
            tot++;
        }
    }
    for(i=0;i<tot;i++)cnt1[i]=tri[i].c;
    sort(cnt1,cnt1+tot);
    for(i=0;i<=1000000;i++)cnt2[i]=0x7fffffff;
    for(i=0;i<tot;i++){
        for(j=1;tri[i].c*j<=1000000;j++){
            cnt2[tri[i].a*j]=min(cnt2[tri[i].a*j],tri[i].c*j);
            cnt2[tri[i].b*j]=min(cnt2[tri[i].b*j],tri[i].c*j);
            cnt2[tri[i].c*j]=tri[i].c*j;
        }
    }
    sort(cnt2,cnt2+1000001);
    while(scanf("%d",&n)==1){
        printf("%d %d\n",(lower_bound(cnt1,cnt1+tot,n+1)-cnt1),n-(lower_bound(cnt2,cnt2+n,n+1)-cnt2));
    }
}
