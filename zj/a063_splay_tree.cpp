#include <cstdio>
#include <iostream>
using namespace std;

struct splay_tree{
    struct node{
        int v,lnum,rnum;
        bool tag;
        node *p,*l,*r;
        node(int v,node* r){
            this->v=v;
            lnum=rnum=0;
            tag=0;
            p=l=0;
            this->r=r;
        }
    };
    node* root;
    int n;
    splay_tree(){
        root=0;
    }
    void left_rot(node *x){
        node* y=x->r;
        x->r=y->l;
        if(y->l)y->l->p=x;
        y->p=x->p;
        if(!x->p)root=y;
        else if(x==x->p->l)x->p->l=y;
        else x->p->r=y;
        y->l=x;
        x->p=y;
        x->rnum=y->lnum;
        y->lnum+=1+x->lnum;
    }
    void right_rot(node *x){
        node* y=x->l;
        x->l=y->r;
        if(y->r)y->r->p=x;
        y->p=x->p;
        if(!x->p)root=y;
        else if(x==x->p->l)x->p->l=y;
        else x->p->r=y;
        y->r=x;
        x->p=y;
        x->lnum=y->rnum;
        y->rnum+=1+x->rnum;
    }
    void splay(node *x){
        while(x->p){
            if(x==x->p->l)right_rot(x->p);
            else left_rot(x->p);
        }
    }
    void init(node* x){
        if(!x)return;
        init(x->l);
        init(x->r);
        delete x;
    }
    void build(int n){
        init(root);
        this->n=n;
        root=new node(n+1,0);
        while(n>=0){
            root->p=new node(n--,root);
            root=root->p;
            root->rnum=root->r->rnum+1;
        }
    }
    void pushdown(node* x){
        if(x->tag){
            x->tag=0;
            swap(x->l,x->r);
            swap(x->lnum,x->rnum);
            if(x->l)x->l->tag=!x->l->tag;
            if(x->r)x->r->tag=!x->r->tag;
        }
    }
    void looking(int x,node* ptr){
        node* tmp=ptr->p;
        ptr->p=0;
        root=ptr;
        while(1){
            pushdown(ptr);
            if(x==ptr->lnum){
                splay(ptr);
                break;
            }else if(x<ptr->lnum){
                ptr=ptr->l;
            }else{
                x-=ptr->lnum+1;
                ptr=ptr->r;
            }
        }
        if(tmp){
            tmp->r=root;
            root->p=tmp;
            root=tmp;
        }
    }
    void edit(int el,int er){
        looking(el-1,root);
        looking(er-root->lnum,root->r);//er+1-(root->lnum+1)
        root->r->l->tag=!root->r->l->tag;
    }
    void dfs(node* x){
        if(!x)return;
        pushdown(x);
        dfs(x->l);
        if(x->v<=n&&x->v)printf("%d ",x->v);
        dfs(x->r);
    }
};
splay_tree st;
int main(){
    int n,m,i,j,el,er;
    while(scanf("%d %d",&n,&m)==2){
        st.build(n);
        while(m--){
            scanf("%d %d",&el,&er);
            st.edit(el,er);
        }
        st.dfs(st.root);
        printf("\n");
    }
}
