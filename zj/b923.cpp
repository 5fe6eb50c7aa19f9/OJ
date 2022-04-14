#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct st{
    int value;
    st* next;
};
int main(){
    int n;
    while(cin>>n){
        st* root=NULL;
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            if(tmp==1){
                if(root!=NULL){
                    root=root->next;
                }
            }else if(tmp==2){
                if(root!=NULL){
                    cout<<root->value<<endl;
                }
            }else{
                cin>>tmp;
                st* tmp2=new st;
                tmp2->value=tmp;
                if(root==NULL){
                    root=tmp2;
                    tmp2->next=NULL;
                }else{
                    tmp2->next=root;
                    root=tmp2;
                }
            }
        }
    }
}
