#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        cin.ignore();
        string data="";
        getline(cin,data);
        char tmp=data[0];
        int rep=0;
        for(int i=1;i<n;i++){
            if(data[i]==tmp){
                rep++;
            }else{
                tmp=data[i];
            }
        }
        data+=" ";
        if(n<=2*(n-rep)){
            cout<<data;
        }else{
            tmp=data[0];
            for(int i=1,num=1;i<n+1;i++){
                if(data[i]==tmp){
                    num++;
                }else{
                    printf("%d%c",num,tmp);
                    num=1;
                    tmp=data[i];
                }
            }
        }
        cout<<endl;
    }
}
