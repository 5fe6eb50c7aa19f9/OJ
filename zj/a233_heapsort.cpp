#include <cstdio>
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
#define Max 0x7fffffff
void Swap(int& a,int& b){
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
}
void push(int* pq,int& n,int x){
    pq[++n]=x,pq[n<<1]=Max,pq[(n<<1)+1]=Max;
    for(int i=n;i!=1&&pq[i]<pq[i>>1];i>>=1){
        Swap(pq[i],pq[i>>1]);
    }
}
void pop(int* pq,int& n){
    pq[1]=pq[n],pq[n--]=Max;
    for(int i=1;;){
        if(pq[i<<1]<pq[(i<<1)+1]){
            if(pq[i<<1]<pq[i]){
                Swap(pq[i<<1],pq[i]);
                i<<=1;
            }else{
                break;
            }
        }else{
            if(pq[(i<<1)+1]<pq[i]){
                Swap(pq[(i<<1)+1],pq[i]);
                i=(i<<1)+1;
            }else{
                break;
            }
        }
    }
}
int pq[1000001]={0};
int main(){
    int n=0,tmp,i;
    while(scanf("%d",&i)==1){
        while(i>0){
            i--;
            scanf("%d",&tmp);
            push(pq,n,tmp);
        }
        while(n>0){
            printf("%d ",pq[1]);
            pop(pq,n);
        }
        cout<<endl;
    }
}
