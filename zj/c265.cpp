#include <cstdio>
#include <iostream>
using namespace std;
struct ST{
    int l,r,lp,rp,bit;
    char mod[51];//0~50
};
struct ANS{
    int bit,remain;
};
char ten[400001][51];//ten[x][y]=(10^x)%y
int data[100000];
ST st[200000];
int num;
void cons(int i,int l,int r){
    st[i].l=l,st[i].r=r;
    if(l+1==r){
        st[i].bit=1;
        for(int j=10;j<=data[l];j*=10){
            st[i].bit++;
        }
        for(int j=1;j<=50;j++){
            st[i].mod[j]=data[l]%j;
        }
        return;
    }
    int m=(l+r)/2;
    st[i].lp=num++,st[i].rp=num++;
    cons(st[i].lp,l,m);
    cons(st[i].rp,m,r);
    st[i].bit=st[st[i].lp].bit+st[st[i].rp].bit;
    for(int j=1;j<=50;j++){
        st[i].mod[j]=( ((int)st[st[i].lp].mod[j])*((int)ten[st[st[i].rp].bit][j])+((int)st[st[i].rp].mod[j]) )%j;
    }
}
void edit(int i,int x,int v){
    if(st[i].l==x&&st[i].r==x+1){
        data[x]=v;
        st[i].bit=1;
        for(int j=10;j<=data[x];j*=10){
            st[i].bit++;
        }
        for(int j=1;j<=50;j++){
            st[i].mod[j]=data[x]%j;
        }
        return;
    }
    int m=(st[i].l+st[i].r)/2;
    if(x<m){
        edit(st[i].lp,x,v);
    }else{
        edit(st[i].rp,x,v);
    }
    st[i].bit=st[st[i].lp].bit+st[st[i].rp].bit;
    for(int j=1;j<=50;j++){
        st[i].mod[j]=( ((int)st[st[i].lp].mod[j])*((int)ten[st[st[i].rp].bit][j])+((int)st[st[i].rp].mod[j]) )%j;
    }
}
ANS query(int i,int ql,int qr,int mod){
    if(st[i].l==ql&&st[i].r==qr){
        ANS ans;
        ans.bit=st[i].bit;
        ans.remain=st[i].mod[mod];
        return ans;
    }
    int m=(st[i].l+st[i].r)/2;
    if(qr<=m){
        return query(st[i].lp,ql,qr,mod);
    }else if(ql>=m){
        return query(st[i].rp,ql,qr,mod);
    }else{
        ANS a=query(st[i].lp,ql,m,mod);
        ANS b=query(st[i].rp,m,qr,mod);
        a.bit+=b.bit;
        a.remain=(a.remain*((int)ten[b.bit][mod])+b.remain)%mod;
        return a;
    }
}
int main(){
    int n,q,i,j,o,x,v,l,r,k;
    for(i=0;i<=400000;i++){
        for(j=2;j<=50;j++){
            if(i==0){
                ten[i][j]=1;
            }else{
                ten[i][j]=((int)ten[i-1][j])*10%j;
            }
        }
    }
    while(scanf("%d %d",&n,&q)==2){
        for(i=0;i<n;i++){
            scanf("%d",data+i);
        }
        num=1;
        cons(0,0,n);
        while(q--){
            scanf("%d",&o);
            if(o==1){
                scanf("%d %d",&x,&v);
                edit(0,x-1,v);
            }else if(o==2){
                scanf("%d %d %d",&l,&r,&k);
                if(query(0,l-1,r,k).remain==0){
                    printf("YES\n");
                }else{
                    printf("NO\n");
                }
            }
        }
    }
}
