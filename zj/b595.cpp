#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool stop[31];
bool res[31];
int penalty;
void go(int* data,int now,int last,int p){
    if(now==last){
        penalty=p;
        for(int i=0;i<=last;i++)res[i]=stop[i];
        return;
    }
    for(int i=now+1;i<=last;i++){
        int tmp=200-(data[i]-data[now]);
        tmp*=tmp;
        if(p+tmp>=penalty)continue;
        stop[i]=true;
        go(data,i,last,p+tmp);
        stop[i]=false;
    }
}
int main(){
    int n;
    while(cin>>n){
        if(n==0)break;
        penalty=0x7fffffff;
        int data[n+1];
        data[0]=0;
        stop[0]=true;
        for(int i=1;i<=n;i++){
            cin>>data[i];
            stop[i]=false;
        }
        go(data,0,n,0);
        for(int i=0;i<=n;i++){
            if(res[i])cout<<i<<' ';
        }
        cout<<endl;
    }
}
