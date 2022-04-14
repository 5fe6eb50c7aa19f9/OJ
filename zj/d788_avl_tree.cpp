#include <cstdio>
#include <iostream>
using namespace std;

struct node{
    int v,ld,rd,la,ra;//value;deep of l&r node;l&r node amount
    node *l,*r;
    node(){
        ld=rd=la=ra=0;
        l=r=0;
    }
};
int ans;
void rl(node* pivot,node* root){//rotate left
    root->r=pivot->l;
    root->rd=pivot->ld;
    root->ra=pivot->la;
    pivot->l=root;
    pivot->ld=max(root->ld,root->rd)+1;
    pivot->la=root->la+root->ra+1;
    swap(*pivot,*root);
    root->l=pivot;//important
}
void rr(node* pivot,node* root){//rotate right
    root->l=pivot->r;
    root->ld=pivot->rd;
    root->la=pivot->ra;
    pivot->r=root;
    pivot->rd=max(root->ld,root->rd)+1;
    pivot->ra=root->la+root->ra+1;
    swap(*pivot,*root);
    root->r=pivot;//important
}
int ins(int x,node* now){//insert x to node now
    if(x<now->v){
        ans+=now->ra+1;
        now->la++;
        if(now->l)now->ld=ins(x,now->l);
        else now->l=new node,now->l->v=x,now->ld=1;
    }else if(x>now->v){
        now->ra++;
        if(now->r)now->rd=ins(x,now->r);
        else now->r=new node,now->r->v=x,now->rd=1;
    }

    //rotate
    if(now->ld-now->rd==2){
        if(now->l->ld-now->l->rd==-1)rl(now->l->r,now->l);
        rr(now->l,now);
    }else if(now->ld-now->rd==-2){
        if(now->r->ld-now->r->rd==1)rr(now->r->l,now->r);
        rl(now->r,now);
    }
    return max(now->ld,now->rd)+1;
}
void del(node* now){//delete
    if(now->l){
        del(now->l);
    }
    if(now->r){
        del(now->r);
    }
    delete now;
}
int main(){
    int n,i,tmp;
    node* root;
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++){
            ans=1;
            scanf("%d",&tmp);
            if(i==0){
                root=new node;
                root->v=tmp;
            }else{
                ins(tmp,root);
            }
            printf("%d\n",ans);
        }
        del(root);
    }
}
