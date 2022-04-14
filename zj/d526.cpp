#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct tree{
    int num,l,r;
    tree* le;
    tree* ri;
};
void go(tree* now){
    cout<<now->num<<' ';
    if(now->l!=0)go(now->le);
    if(now->r!=0)go(now->ri);
}
int main(){
    int n;
    while(cin>>n){
        tree data[n];
        cin>>data[0].num;
        data[0].l=0;
        data[0].r=0;
        for(int i=1;i<n;i++){
            cin>>data[i].num;
            data[i].l=0;
            data[i].r=0;
            tree* tmp=&data[0];
            while(true){
                if(tmp->num>data[i].num){
                    if(tmp->l==0){
                        tmp->l=data[i].num;
                        tmp->le=&data[i];
                        break;
                    }else{
                        tmp=tmp->le;
                    }
                }else if(tmp->num<data[i].num){
                    if(tmp->r==0){
                        tmp->r=data[i].num;
                        tmp->ri=&data[i];
                        break;
                    }else{
                        tmp=tmp->ri;
                    }
                }
            }
        }
        go(&data[0]);
        cout<<endl;
    }
}
