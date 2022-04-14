#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int a,sum;
int siterecord[30];
bool exist=false;
void analyze(int* data,int i,int nowsum,int flag){
    if(sum==nowsum){
        for(int j=0;j<flag;j++){
            cout<<*(data+siterecord[j])<<" ";
        }
        cout<<endl;
        exist=true;
        return;
    }else if(nowsum>sum||i>=a)return;
    for(;i<a;i++){
        siterecord[flag]=i;
        analyze(data,i+1,nowsum+data[i],flag+1);
    }
}
int main()
{
    while(cin>>a>>sum){
        vector<int> data;
        for(int i=0;i<a;i++){
            int tmp;
            cin>>tmp;
            data.push_back(tmp);
        }
        sort(data.begin(),data.end());
        for(int i=0;i<a;i++){
            siterecord[0]=i;
            analyze(&data[0],i+1,data[i],1);
        }
        if(!exist)cout<<"-1\n";
    }
}
