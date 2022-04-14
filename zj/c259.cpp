#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define MAXN 300000
#define SQUN 600

int n,m,blksize;
struct Sol{
    struct Dat{
        int id,l,r;
        ll v;
        bool operator<(Dat& o){
            if(id/blksize!=o.id/blksize)return id<o.id;
            return v<o.v;
        }
    };
    Dat dat[MAXN];
    ll acc[MAXN];
    ll sum[SQUN];
    ll minv[SQUN];
    int pos[SQUN];
    Dat stk1[SQUN],stk2[SQUN];
    void edit2(int l,int r,ll v){
        int i,j,k=l/blksize,a,b,c,d;
        if(minv[k]>=v)return;
        if(l%blksize==0&&r+1==n||r-l+1==blksize){
            i=pos[k];
            j=min((k+1)*blksize,n);
            while(i+1<j&&dat[i+1].v<=v){
                i=dat[i+1].r;
            }
            sum[k]=acc[j-1]-acc[i]+v*(i%blksize+1);
            minv[k]=v;
            pos[k]=i;
        }else{
            i=k*blksize;
            j=min((k+1)*blksize,n);
            a=b=0;
            while(i<j&&dat[i].v<v){
                if(dat[i].id>=l&&dat[i].id<=r){
                    dat[i].v=v;
                    stk1[a++]=dat[i];
                }else{
                    dat[i].v=max(dat[i].v,minv[k]);
                    stk2[b++]=dat[i];
                }
                i++;
            }
            for(i=k*blksize,c=d=0;i<j;i++){
                if(d<b){
                    dat[i]=stk2[d++];
                }else if(c<a){
                    dat[i]=stk1[c++];
                }
                dat[i].l=dat[i].r=i;
                acc[i]=dat[i].v;
                if(i%blksize){
                    if(dat[i].v==dat[i-1].v){
                        dat[i].l=dat[i-1].l;
                        dat[dat[i].l].r=i;
                    }
                    acc[i]+=acc[i-1];
                }
            }
            sum[k]=acc[j-1];
            minv[k]=dat[k*blksize].v;
            pos[k]=dat[k*blksize].r;
        }
    }
    void edit1(int l,int r,ll v){
        if(l/blksize==r/blksize){
            edit2(l,r,v);
        }else{
            int m=min((l/blksize+1)*blksize-1,r);
            while(l<=r){
                edit2(l,m,v);
                l=m+1;
                m=min(m+blksize,r);
            }
        }
    }
    ll query2(int l,int r){
        if(l%blksize==0&&r+1==n||r-l+1==blksize)return sum[l/blksize];
        int i,j,k;
        ll ret=0;
        for(i=pos[l/blksize]+1,j=min((l/blksize+1)*blksize,n),k=0;i<j;i++){
            if(dat[i].id>=l&&dat[i].id<=r){
                ret+=dat[i].v;
                k++;
            }
        }
        return ret+minv[l/blksize]*(r-l+1-k);
    }
    ll query1(int l,int r){
        if(l/blksize==r/blksize)return query2(l,r);
        ll ret=0;
        int m=min((l/blksize+1)*blksize-1,r);
        while(l<=r){
            ret+=query2(l,m);
            l=m+1;
            m=min(m+blksize,r);
        }
        return ret;
    }
    void ini(){
        int i,j,k;
        ll tmp;
        for(i=0;i<n;i++){
            dat[i].id=i;
            scanf("%lld",&dat[i].v);
        }
        sort(dat,dat+n);
        for(i=0;i<n;i=k){
            k=min(i+blksize,n);
            for(j=i;j<k;j++){
                dat[j].l=dat[j].r=j;
                acc[j]=dat[j].v;
                if(j!=i){
                    if(dat[j].v==dat[j-1].v){
                        dat[j].l=dat[j-1].l;
                        dat[dat[j].l].r=j;
                    }
                    acc[j]+=acc[j-1];
                }
            }
            sum[i/blksize]=acc[k-1];
            minv[i/blksize]=dat[i].v;
            pos[i/blksize]=dat[i].r;
        }
        while(m--){
            scanf("%d %d %d",&i,&j,&k);
            if(i==1){
                scanf("%lld",&tmp);
                edit1(j-1,k-1,tmp);
            }else{
                printf("%lld\n",query1(j-1,k-1));
            }
        }
    }
};
Sol sol;
int main(){
    int i,j;
    while(scanf("%d %d",&n,&m)==2){
        blksize=sqrt(n);
        sol.ini();
    }
}
