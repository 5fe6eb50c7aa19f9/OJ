#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
    int l,r;//left and right part
};
bool cmp(node &a,node &b){//compare to left part
    if(a.l!=b.l)return a.l<b.l;//avoid problems when merge sort encounter l_a==l_b&&r_a!=r_b
    return a.r<b.r;
}
node data[1000000];
long long n,ans;
struct cmpr{//compare to right part
    bool operator()(int &a,int &b){
        return data[a].r>data[b].r;
    }
};
priority_queue<int,vector<int>,cmpr> pqr;//priority for right value
void ms(int l,int r){//merge sort for finding anti-order pairs
    if(l+1>=r)return;
    int m=(l+r)>>1,i,j,k,flag;
    ms(l,m);
    ms(m,r);
    node tmp[r-l];
    for(i=0,j=l,k=m,flag=m;i<r-l;i++){
        if(j==m){
            tmp[i]=data[k++];
        }else if(k==r){
            while(flag<r&&data[j].r>data[flag].r)flag++;
            ans+=flag-m;
            tmp[i]=data[j++];
        }else if(data[j].r<data[k].r){
            while(flag<r&&data[j].r>data[flag].r)flag++;
            ans+=flag-m;
            tmp[i]=data[j++];
        }else{
            tmp[i]=data[k++];
        }
    }
    for(int i=0,j=l;i<r-l;i++,j++){
        data[j]=tmp[i];
    }
}
int main() {
    int i,j,k;
    while(scanf("%lld",&n)==1){
        ans=0;
        while(!pqr.empty())pqr.pop();
        for(i=0;i<n;i++){
            scanf("%d %d",&j,&k);
            data[i].l=j-k,data[i].r=j+k;
        }
        sort(data,data+n,cmp);
        for(i=0;i<n;i++){//finding pairs that don't overlap
            while(!pqr.empty()&&data[pqr.top()].r<data[i].l)pqr.pop();
            ans+=pqr.size();
            pqr.push(i);
        }
        ans=n*(n-1)/2-ans;
        ms(0,n);
        printf("%lld\n",ans);
    }
}
