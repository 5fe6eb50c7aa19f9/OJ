#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
    char v;
    node *bro,*son;
    node(){
        v=0;
        bro=son=0;
    }
};
char data[100];
int ans;
node *root;
void ins(int i,node *now,int ret){
    if(!data[i])return;

    node *tmp,*next;
    if(now->son){
        tmp=0;
        next=now->son;
        while(next&&next->v<=data[i]){
            tmp=next;
            next=next->bro;
        }
        if(tmp){
            if(tmp->v==data[i]){
                ret++;
                ans=max(ans,ret);
                ins(i+1,tmp,ret);
            }else{
                tmp->bro=new node;
                tmp->bro->v=data[i];
                tmp->bro->bro=next;
                ins(i+1,tmp->bro,0);
            }
        }else{
            tmp=new node;
            tmp->v=data[i];
            tmp->bro=next;
            now->son=tmp;
            ins(i+1,tmp,0);
        }
    }else{
        now->son=new node;
        now->son->v=data[i];
        ins(i+1,now->son,0);
    }
}
void del(node *now){
    if(now->bro){
        del(now->bro);
    }
    if(now->son){
        del(now->son);
    }
    delete now;
}
int main(){
    int n,i;
    while(scanf("%d\n",&n)==1&&n){
        ans=0;
        root=new node;
        for(i=0;i<n;i++){
            scanf("%[^\n]%*c",data);
            ins(0,root,0);
        }
        printf("%d\n",ans);
        del(root);
    }
}
