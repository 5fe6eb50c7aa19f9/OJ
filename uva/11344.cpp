#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int t,i,j,k,n,s;
    bool flag;
    string data,tmp;
    scanf("%d",&t);
    getline(cin,tmp);
    while(t--){
        getline(cin,data);
        scanf("%d",&n);
        flag=0;
        while(n--){
            scanf("%d",&s);
            for(i=0,j=0;i<data.size();i++){
                j=j*10+data[i]-'0';
                j%=s;
            }
            if(j!=0)flag=1;
        }
        getline(cin,tmp);
        cout<<data;
        if(flag){
            printf(" - Simple.\n");
        }else{
            printf(" - Wonderful.\n");
        }
    }
}
