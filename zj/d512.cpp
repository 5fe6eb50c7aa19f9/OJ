#include <cstdio>
#include <iostream>
using namespace std;
struct node{
    int v,ld,rd;
    node *lp,*rp;
};
node avl[100000];
int num;
int data[20];
int N;
void wise(node *pivot,node *root){
    root->lp=pivot->rp;
    root->ld=pivot->rd;
    pivot->rp=pivot;
    pivot->rd=max(root->ld,root->rd)+1;
    swap(*pivot,*root);
}
void counterwise(node *pivot,node *root){
    root->rp=pivot->lp;
    root->rd=pivot->ld;
    pivot->lp=pivot;
    pivot->ld=max(root->ld,root->rd)+1;
    swap(*pivot,*root);
}
void ins(node *now,int v){
    if(now->v>v){
        if(now->rp){
            ins(now->rp,v);
            now->rd=max(now->rp->ld,now->rp->rd)+1;
        }else{
            avl[num].v=v;
            avl[num].lp=avl[num].rp=0;
            avl[num].ld=avl[num].rd=0;
            now->rp=&avl[num++];
            return;
        }
    }else if(now->v<v){
        if(now->lp){
            ins(now->lp,v);
            now->ld=max(now->lp->ld,now->lp->rd)+1;
        }else{
            avl[num].v=v;
            avl[num].lp=avl[num].rp=0;
            avl[num].ld=avl[num].rd=0;
            now->lp=&avl[num++];
            return;
        }
    }
    if(now->ld-now->rd==2){
        if(now->lp->ld-now->lp->rd==-1){
            counterwise(now->lp->rp,now->lp);
        }
        wise(now->lp,now);
    }else if(now->ld-now->rd==-2){
        if(now->rp->ld-now->rp->rd==1){
            wise(now->rp->lp,now->rp);
        }
        counterwise(now->rp,now);
    }
}
void brute(int *data,int N,int sum){
    if(N==0){
        ins(&avl[0],sum);
        return;
    }
    brute(data+1,N-1,sum+*data);
    brute(data+1,N-1,sum);
}
int main(){
    int i,v;
    while(scanf("%d",&N)==1){
        num=1;
        avl[0].v=0;
        avl[0].lp=avl[0].rp=0;
        avl[0].ld=avl[0].rd=0;
        for(i=0;i<N;i++){
            scanf("%d",data+i);
        }
        brute(data,N,0);
        printf("%d\n",num-1);
    }
}

