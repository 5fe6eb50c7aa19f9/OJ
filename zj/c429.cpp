#include <cstdio>
#define LL long long
#define maxseg 6
#define maxv 1000000

char s1[400000],s2[400],*s;
struct bigint{
    LL v[60000];
    int t;
    static bool cmp(bigint& a,int a1,int a2,bigint& b,int b1,int b2){
        if(a2-a1!=b2-b1)return a2-a1>b2-b1;
        for(int i=a1,j=b1;i<=a2;i++,j++){
            if(a.v[i]!=b.v[j])return a.v[i]>b.v[j];
        }
        return 1;
    }
    static void mul(bigint& a,LL v,bigint& b){//a=b*v
        a.t=b.t;
        int i;
        a.v[a.t]=b.v[b.t]*v;
        for(i=a.t-1;i>=0;i--){
            a.v[i]=b.v[i]*v;
            a.v[i]+=a.v[i+1]/maxv;
            a.v[i+1]%=maxv;
        }
    }
    static void sub(bigint& a,int a1,int a2,bigint& b,int b1,int b2){//a-=b
        int i,j;
        for(i=a2,j=b2;i>a1;i--,j--){
            a.v[i]-=b.v[j];
            if(a.v[i]<0){
                a.v[i]+=maxv;
                a.v[i-1]--;
            }
        }
        a.v[i]-=b.v[j];
    }
    static void add(bigint& a,int a1,int a2,bigint& b,int b1,int b2){//a+=b
        for(int i=a2,j=b2;i>=a1;i--,j--){
            a.v[i]+=b.v[j];
            a.v[i-1]+=a.v[i]/maxv;
            a.v[i]%=maxv;
        }
    }
    static void div(bigint& a,bigint& b,bigint& delta){//a/=b
        int i,j,flag;
        LL ans,b0b1;
        if(!cmp(a,0,a.t,b,0,b.t)){//a<b
            printf("0\n");
        }else if(b.t==0){
            for(i=0,flag=0;i<=a.t;i++){
                if(flag){
                    printf("%06lld",a.v[i]/b.v[0]);
                }else if(a.v[i]/b.v[0]){
                    flag=1;
                    printf("%lld",a.v[i]/b.v[0]);
                }
                a.v[i+1]+=(a.v[i]%b.v[0])*maxv;
            }
            printf("\n");
        }else{
            for(i=0,j=b.t,flag=0,b0b1=b.v[0]*maxv+b.v[1];j<=a.t;i++,j++){
                ans=(a.v[i]*maxv+a.v[i+1])/b0b1;
                mul(delta,ans,b);
                sub(a,i,j,delta,0,delta.t);
                if(a.v[i]<0){
                    ans--;
                    add(a,i,j,b,0,b.t);
                }
                a.v[i+1]+=a.v[i]*maxv;
                if(flag){
                    printf("%06lld",ans);
                }else if(ans){
                    flag=1;
                    printf("%lld",ans);
                }
            }
            printf("\n");
        }
    }
};
bigint n,m,tmp;
void read(bigint& ret){
    ret.v[0]=0;
    ret.t=0;
    int i,j;
    for(j=0;s[j];j++);
    j%=maxseg;
    if(j==0)ret.t--;
    for(i=0;s[i];i++){
        if(i%maxseg==j)ret.v[++ret.t]=0;
        ret.v[ret.t]=ret.v[ret.t]*10+s[i]-'0';
    }
}
int main(){
    int t,k=0;
    scanf("%d",&t);
    while(t--){
        scanf("%s %s",s1,s2);
        s=s1;
        read(n);
        s=s2;
        read(m);
        bigint::div(n,m,tmp);
    }
}
