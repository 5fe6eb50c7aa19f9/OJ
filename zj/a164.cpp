#include <cstdio>
#include <iostream>
using namespace std;

struct ST{
    int l,r,lp,rp,sum;//range:l~r;pointer of l&r node;sum of data[l]~data[r];
    //left must take data[l],right must take data[r],whole no limit
    int left,right,whole;//max sum of data[l]~data[lrb]&data[rlb]~data[r]&data[wlb]~data[wrb];
    int lrb,rlb,wlb,wrb;//right "closed bound" of left....
};
ST st[400000];
int used;
int data[200000];

void construct(int num,int l,int r){//"num" is the pointer of this node;range of the node is [l,r)
    st[num].l=l,st[num].r=r;
    if(l==r-1){
        st[num].sum=st[num].left=st[num].right=st[num].whole=data[l];
        st[num].lrb=st[num].rlb=st[num].wlb=st[num].wrb=l;
        return;
    }
    int mid=(l+r)/2;
    st[num].lp=used++,st[num].rp=used++;
    construct(st[num].lp,l,mid);
    construct(st[num].rp,mid,r);
    st[num].sum=st[st[num].lp].sum+st[st[num].rp].sum;

    st[num].left=max(st[st[num].lp].left,st[st[num].lp].sum+st[st[num].rp].left);
    st[num].lrb=(st[num].left==st[st[num].lp].left?st[st[num].lp].lrb:st[st[num].rp].lrb);//ensure lrb is least

    st[num].right=max(st[st[num].rp].right,st[st[num].rp].sum+st[st[num].lp].right);
    st[num].rlb=(st[num].right==st[st[num].rp].sum+st[st[num].lp].right?st[st[num].lp].rlb:st[st[num].rp].rlb);

    st[num].whole=max(st[st[num].lp].whole,st[st[num].lp].right+st[st[num].rp].left);
    if(st[num].whole==st[st[num].lp].whole){
        st[num].wlb=st[st[num].lp].wlb,st[num].wrb=st[st[num].lp].wrb;
    }else{
        st[num].wlb=st[st[num].lp].rlb,st[num].wrb=st[st[num].rp].lrb;
    }
    if(st[num].whole<st[st[num].rp].whole){
        st[num].whole=st[st[num].rp].whole;
        st[num].wlb=st[st[num].rp].wlb,st[num].wrb=st[st[num].rp].wrb;
    }
}
ST quest(int num,int ql,int qr){
    if(st[num].l==ql&&st[num].r==qr){
        return st[num];
    }
    int mid=(st[num].l+st[num].r)/2;
    if(qr<=mid){
        return quest(st[num].lp,ql,qr);
    }else if(ql>=mid){
        return quest(st[num].rp,ql,qr);
    }
    ST A=quest(st[num].lp,ql,mid);
    ST B=quest(st[num].rp,mid,qr);
    ST tot;

    tot.left=max(A.left,A.sum+B.left);
    tot.lrb=(tot.left==A.left?A.lrb:B.lrb);

    tot.right=max(B.right,B.sum+A.right);
    tot.rlb=(tot.right==B.sum+A.right?A.rlb:B.rlb);

    tot.whole=max(A.whole,A.right+B.left);
    if(tot.whole==A.whole){
        tot.wlb=A.wlb,tot.wrb=A.wrb;
    }else{
        tot.wlb=A.rlb,tot.wrb=B.lrb;
    }
    if(tot.whole<B.whole){
        tot.whole=B.whole;
        tot.wlb=B.wlb,tot.wrb=B.wrb;
    }

    tot.sum=A.sum+B.sum;
    return tot;
}
int main(){
    int Case=0,N,Q,L,R,i;
    while(scanf("%d %d",&N,&Q)==2){
        Case++;
        for(i=0;i<N;i++)scanf("%d",data+i);
        used=1;
        construct(0,0,N);
        printf("Case %d:\n",Case);
        while(Q--){
            scanf("%d %d",&L,&R);
            ST tot=quest(0,L-1,R);
            printf("%d %d %d\n",tot.wlb+1,tot.wrb+1,tot.whole);
        }
    }
}
