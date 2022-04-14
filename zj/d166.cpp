#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    string n;
    while(getline(cin,n)){
        if(n=="-1")break;
        int data[100]={0};
        int tmp=0;
        for(int i=0;i<n.size();i++){
            if(n[i]==' ')continue;
            for(int j=i;j<n.size()&&n[j]!=' ';j++){
                data[tmp]*=10;
                data[tmp]+=n[j]-'0';
                i=j;
            }
            tmp++;
        }
        int re[100]={0};
        for(int i=1;i<=tmp;i++){
            for(int j=0,tag=0;j<tmp;j++){
                if(re[j]==0)tag++;
                if(tag==data[i-1]+1){
                    re[j]=i;
                    break;
                }
            }
        }
        for(int i=0;i<tmp;i++)printf("%d ",re[i]);
        cout<<endl;
    }
}
