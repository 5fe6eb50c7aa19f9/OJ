#include <iostream>
#include <cstdio>
using namespace std;
struct link{
    int beg,num;
    link* next;
    link(){
        next=0;
        num=0;
    }
};
int main(){
    int i;
    string a;
    link *f,*r,*tmp;//front,rear
    while(getline(cin,a)){
        tmp=new link;
        tmp->beg=0;
        f=r=tmp;
        for(i=0;i<a.size();i++){
            if(a[i]=='['){
                tmp=new link;
                tmp->beg=i+1;
                tmp->next=f;
                f=tmp;
            }else if(a[i]==']'){
                tmp=new link;
                tmp->beg=i+1;
                r->next=tmp;
                r=tmp;
            }else{
                tmp->num++;
            }
        }
        while(f){
            cout<<a.substr(f->beg,f->num);
            tmp=f;
            f=f->next;
            delete tmp;
        }
        cout<<endl;
    }
}
