#include <iostream>
#include <cstdio>
using namespace std;

string a;
bool cmp(int d,char* x,char* y){
    for(int i=0;i<d;i++){
        if(*(x+i)<*(y+i))return true;
        if(*(x+i)>*(y+i))return false;
    }
    return true;
}
void Merge(int n,int* data,int d){
    if(n==1)return;
    Merge(n/2,data,d);
    Merge(n/2+n%2,data+n/2,d);
    int tmp1[n/2];
    int tmp2[n/2+n%2];
    for(int i=0;i<n/2;i++)tmp1[i]=data[i];
    for(int i=0;i<n/2+n%2;i++)tmp2[i]=data[n/2+i];
    for(int i=0,j=0,k=0;i<n;i++){
        if((k==n/2+n%2)||(j<n/2&&cmp(d,&a[(tmp1[j])],&a[(tmp2[k])]))){
            data[i]=tmp1[j];
            j++;
        }else{
            data[i]=tmp2[k];
            k++;
        }
    }
    return;
}
int go(int d){
    int flag=0;
    int data[a.size()/d];
    for(int i=0,j=0;i<a.size();i+=d,j++)data[j]=i;
    Merge(a.size()/d,data,d);
    for(int i=0,j=0;i<a.size();i+=d,j++){
        if(data[j]!=i){
            flag=1;
            break;
        }
    }
    if(flag==1){
        for(int i=0;i<a.size()/d;i++){
            for(int j=0;j<d;j++){
                cout<<a[data[i]+j];
            }
        }
        cout<<endl;
    }
    return flag;
}
int main(){
    while(cin>>a){
        int flag=0;
        for(int i=1;i<a.size();i++){
            if(a.size()%i==0)flag+=go(i);
        }
        if(flag==0)cout<<"bomb!\n";
    }
}
