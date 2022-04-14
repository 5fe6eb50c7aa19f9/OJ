#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct STx{
    int l,r,lt,rt,index;
};
struct STy{
    int l,r,lt,rt,v;
};
int data[500][500];
int n,m;
STx stx[1000];
STy sty[1000000];
int numx,numy;

void buildy(int i,int l,int r,int x1,int x2);
void buildx(int i,int l,int r);
int queryy(int i,int y1,int y2);
int queryx(int i,int x1,int x2,int y1,int y2);

int main(){
    int i,j,q,x1,x2,y1,y2;
    while(scanf("%d %d",&n,&m)==2){
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",data[i]+j);
            }
        }
        numx=numy=0;
        buildx(numx++,0,n);
        scanf("%d",&q);
        while(q--){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            printf("%d\n",queryx(0,x1-1,x2,y1-1,y2));
        }
    }
}

void buildy(int i,int l,int r,int x1,int x2){
    sty[i].l=l,sty[i].r=r;
    if(l+1==r){
        if(x2==-1){
            sty[i].v=data[x1][l];
        }else{
            sty[i].v=max(sty[x1].v,sty[x2].v);
        }
        return;
    }
    int mid=(l+r)>>1;
    sty[i].lt=numy++,sty[i].rt=numy++;
    if(x2==-1){
        buildy(sty[i].lt,l,mid,x1,x2);
        buildy(sty[i].rt,mid,r,x1,x2);
    }else{
        buildy(sty[i].lt,l,mid,sty[x1].lt,sty[x2].lt);
        buildy(sty[i].rt,mid,r,sty[x1].rt,sty[x2].rt);
    }
    sty[i].v=max(sty[sty[i].lt].v,sty[sty[i].rt].v);
}
void buildx(int i,int l,int r){
    stx[i].l=l,stx[i].r=r;
    if(l+1==r){
        stx[i].index=numy++;
        buildy(stx[i].index,0,m,l,-1);//only a row
        return;
    }
    int mid=(l+r)>>1;
    stx[i].lt=numx++,stx[i].rt=numx++;
    buildx(stx[i].lt,l,mid);
    buildx(stx[i].rt,mid,r);
    stx[i].index=numy++;
    buildy(stx[i].index,0,m,stx[stx[i].lt].index,stx[stx[i].rt].index);
}
int queryy(int i,int y1,int y2){
    if(sty[i].l==y1&&sty[i].r==y2){
        return sty[i].v;
    }
    int mid=(sty[i].l+sty[i].r)>>1;
    if(y1>=mid){
        return queryy(sty[i].rt,y1,y2);
    }else if(y2<=mid){
        return queryy(sty[i].lt,y1,y2);
    }else{
        return max(queryy(sty[i].lt,y1,mid),queryy(sty[i].rt,mid,y2));
    }
}
int queryx(int i,int x1,int x2,int y1,int y2){
    if(stx[i].l==x1&&stx[i].r==x2){
        return queryy(stx[i].index,y1,y2);
    }
    int mid=(stx[i].l+stx[i].r)>>1;
    if(x1>=mid){
        return queryx(stx[i].rt,x1,x2,y1,y2);
    }else if(x2<=mid){
        return queryx(stx[i].lt,x1,x2,y1,y2);
    }else{
        return max(queryx(stx[i].lt,x1,mid,y1,y2),queryx(stx[i].rt,mid,x2,y1,y2));
    }
}
