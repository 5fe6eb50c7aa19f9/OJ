#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int i,tmp,len,ans;
    string data;
    while(getline(cin,data)){
        len=tmp=0;
        for(i=0;i<data.size();i++){
            if(data[i]==' '){
                tmp++;
            }else{
                len=max(len,tmp);
                tmp=0;
            }
        }
        ans=0;
        while(len>1){
            len=len/2+len%2;
            ans++;
        }
        printf("%d\n",ans);
    }
}
