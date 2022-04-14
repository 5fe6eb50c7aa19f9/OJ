#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long

struct dec{
    ll f[10];
    int num;
    dec(){
        num=0;
    }
    void add(ll v){
        f[num++]=v;
    }
};
struct Tri{
    ll a,b,c;
};
dec factor[1000001];
int seive[1000050>>5];
Tri tri[200000];
int tot;
ll cnt1[200000];
ll cnt2[1000001];
void sol(int i,int now,ll a,ll b){
    if(a>=b)return;
    if(now==factor[i].num){
        ll tmp=a;
        a=(a+b)>>1;
        b=(b-tmp)>>1;
        if(i<b&&a<=1000000){
            tri[tot].a=i,tri[tot].b=b,tri[tot].c=a;
            tot++;
        }
        return;
    }
    if(factor[i].f[now]==2){
        ll tmp=1;
        while(b%2==0){
            b>>=1;
            tmp<<=1;;
        }
        if(tmp>=8){
            sol(i,now+1,a*2,b*tmp/2);
            sol(i,now+1,a*tmp/2,b*2);
        }
        return;
    }
    sol(i,now+1,a,b);//not to get the factor
    //if (z-y) and (z+y) have same factor,then gcd(x,y,z)!=1
    while(b%factor[i].f[now]==0){
        a*=factor[i].f[now];
        b/=factor[i].f[now];
    }
    sol(i,now+1,a,b);//get the factor
}
int main(){
    ll i,j,k,n;
    for(i=2;i<1000050;i++){
        if(((seive[i>>5]>>(i&31))&1)==0){
            for(j=i;j<1000050;j+=i){
                seive[j>>5]|=1<<(j&31);
                if(j<=1000000)factor[j].add(i);
            }
        }
        if(i<=1000000)sol(i,0,1,i*i);//x*x=(z-y)*(z+y)
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
    while(scanf("%lld",&n)==1){
        printf("%d %d\n",(lower_bound(cnt1,cnt1+tot,n+1)-cnt1),n-(lower_bound(cnt2,cnt2+1000001,n+1)-cnt2));
    }
}
