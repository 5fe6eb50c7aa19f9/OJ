#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(string a,string b){
    for(int i=0;i<11;i++){
        if(a[i]<b[i])return true;
        if(a[i]>b[i])return false;
    }
    return true;
}
void s(string* now,int n){
    if(n==1)return;
    s(now,n/2);
    s(now+n/2,n/2+n%2);
    string l[n/2];
    string r[n/2+n%2];
    for(int i=0;i<n/2;i++)l[i]=now[i];
    for(int i=0;i<n/2+n%2;i++)r[i]=now[n/2+i];
    for(int i=0,j=0,k=0;i<n;i++){
        if(k==n/2+n%2||(j<n/2&&cmp(l[j],r[k]))){
            now[i]=l[j];
            j++;
        }else{
            now[i]=r[k];
            k++;
        }
    }
    return;
}
int main(){
    int n;
    while(cin>>n){
        string data[n];
        if(n==0){
            continue;
        }
        cin.ignore();
        for(int i=0;i<n;i++){
            getline(cin,data[i]);
        }
        s(data,n);
        for(int i=0;i<n;i++){
            cout<<data[i]<<endl;
        }
    }
}
