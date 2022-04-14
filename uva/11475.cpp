#include <cstdio>
#include <iostream>
using namespace std;
int KMP[100000];
int main(){
    KMP[0]=-1;
    string a,b;
    char tmp;
    int i,j;
    while(getline(cin,a)){
        b="";
        for(i=a.size()-1;i>=0;i--){
            b+=a[i];
        }
        for(i=1,j=-1;i<b.size();i++){
            while(j!=-1&&b[i]!=b[j+1]){
                j=KMP[j];
            }
            if(b[i]==b[j+1])j++;
            KMP[i]=j;
        }
        for(i=0,j=-1;i<a.size();i++){
            while(j!=-1&&a[i]!=b[j+1]){
                j=KMP[j];
            }
            if(a[i]==b[j+1])j++;
        }
        cout<<a;
        for(i=j+1;i<b.size();i++)printf("%c",b[i]);
        cout<<endl;
    }
}
