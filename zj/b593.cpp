#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int sum;
void go(int* data,int len){
    if(len==1){
        sum+=26;
        return;
    }
    while(true){
        sum+=26-data[len-2];
        data[len-1]=data[len-2];
        for(int i=len-1;i>=1;i--){
            if(data[i]==data[i-1]){
                data[i]=27;
                data[i-1]--;
            }
        }
        for(int i=len-1,j=26;i>=1;i--,j--){
            if(data[i]!=27)break;
            data[i]=j;
        }
        if(data[0]==0)break;
    }
    for(int i=len-2,j=26;i>=0;i--,j--)data[i]=j;
    go(data,len-1);
}
int main(){
    string n;
    while(cin>>n){
        if(n=="0")break;
        sum=0;
        int data[n.size()];
        bool flag=false;
        for(int i=0;i<n.size();i++){
            data[i]=n[i]-'a'+1;
            if(i>0&&data[i]<=data[i-1]){
                flag=true;
                break;
            }
        }
        if(flag){
            cout<<'0'<<endl;
            continue;
        }
        sum-=26-data[n.size()-1];
        data[n.size()-1]=26;
        //for(int i=0;i<n.size();i++)cout<<data[i]<<endl;
        go(data,n.size());
        cout<<sum<<endl;
    }
}
