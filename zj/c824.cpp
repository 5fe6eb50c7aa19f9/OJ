#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long
struct Obj{
    ll w,v;
    Obj(){}
    Obj(ll arg1,ll arg2){
        w=arg1;
        v=arg2;
    }
    bool operator<(const Obj& o)const{
        if(w!=o.w)return w<o.w;
        return v>o.v;
    }
};
struct Heap{
    Obj obj[1000001];
    int n;
    Heap(){
        n=0;
    }
    void push(Obj o){
        obj[++n]=o;
        int now,next;
        now=n;
        while(now/2){
            next=now/2;
            if(obj[now]<obj[next]){
                swap(obj[now],obj[next]);
                now=next;
            }else{
                break;
            }
        }
    }
    void pop(){
        obj[1]=obj[n--];
        int now,next;
        now=1;
        while(now*2<=n){
            next=now*2;
            if(next+1<=n&&obj[next+1]<obj[next]){
                next++;
            }
            if(obj[next]<obj[now]){
                swap(obj[now],obj[next]);
                now=next;
            }else{
                break;
            }
        }
    }
};
Heap heap=Heap();
ll sol(){
    ll n,m,w,v,ret=0;
    scanf("%lld %lld",&n,&m);
    while(n--){
        scanf("%lld %lld",&w,&v);
        heap.push(Obj(w,v));
    }
    while(heap.n&&heap.obj[1].w<=m){
        w=heap.obj[1].w;
        v=heap.obj[1].v;
        ret=max(ret,v);
        heap.pop();
        if(heap.n==0){
            break;
        }else if(heap.obj[1].w==w){
            w++;
            v+=heap.obj[1].v;
            heap.pop();
            heap.push(Obj(w,v));
        }else{
            w=heap.obj[1].w;
            heap.push(Obj(w,v));
        }
    }
    return ret;
}
int main() {
    printf("%lld\n",sol());
}
