#include <cstdio>
#include <algorithm>
using namespace std;

struct edge{
    int b,w,next;
};
struct Heap{
    struct node{
        int b,w;
    };
    node data[2000000];
    int num;
    void Push(edge e){
        int i=++num;
        data[i].b=e.b;
        data[i].w=e.w;
        while(i/2&&data[i].w<data[i/2].w){
            swap(data[i],data[i/2]);
            i>>=1;
        }
    }
    void Pop(){
        int i=1,j;
        data[1]=data[num--];
        while(i*2<=num){
            j=i*2;
            if(j+1<=num&&data[j].w>data[j+1].w)j++;
            if(data[i].w<=data[j].w)break;
            swap(data[i],data[j]);
            i=j;
        }
    }
};
edge pool[2000001];
int use;
Heap heap;
int adj[5001];
int visit[5001];
int main(){
    int n,m,y,o,i,j,k;
    while(scanf("%d %d %d %d",&n,&m,&y,&o)==4){
        use=1;
        heap.num=0;
        for(i=1;i<=n;i++){
            adj[i]=0;
            visit[i]=-1;
        }
        while(m--){
            scanf("%d %d %d",&i,&j,&k);
            pool[use].b=j,pool[use].w=k,pool[use].next=adj[i];
            adj[i]=use++;
            pool[use].b=i,pool[use].w=k,pool[use].next=adj[j];
            adj[j]=use++;
        }
        while(adj[y]){
            heap.Push(pool[adj[y]]);
            adj[y]=pool[adj[y]].next;
        }
        while(visit[o]==-1){
            i=heap.data[1].b;
            j=heap.data[1].w;
            heap.Pop();
            if(visit[i]==-1){
                visit[i]=j;
                while(adj[i]){
                    pool[adj[i]].w+=j;
                    heap.Push(pool[adj[i]]);
                    adj[i]=pool[adj[i]].next;
                }
            }
        }
        printf("%d\n",visit[o]);
    }
}
