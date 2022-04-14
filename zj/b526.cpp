#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

int data[200000];//store range points
int range[100000][2];
struct cmpl{//compare left part
    bool operator()(int*& a,int*& b){
        return a[0]>b[0];
    }
};
struct cmpr{//compare right part
    bool operator()(int*& a,int*& b){
        return a[1]>b[1];
    }
};
int main(){
    int i,j,n,m;
    while(scanf("%d %d",&n,&m)==2){
        priority_queue<int*,vector<int*>,cmpl> l;
        priority_queue<int*,vector<int*>,cmpr> r;
        for(i=0;i<m;i++){
            scanf("%d %d",range[i],range[i]+1);
            l.push(range[i]);
            data[i<<1]=range[i][0],data[(i<<1)+1]=range[i][1];
        }
        m<<=1;
        sort(data,data+m);
        for(i=0;i<m;i+=2){
            if(data[i]!=data[i+1]){
                n-=data[i+1]-data[i]-1;
            }
        }
        for(i=0;i<m;i++){
            while(i+1<m&&data[i]==data[i+1])i++;
            while(!l.empty()&&l.top()[0]<=data[i]){
                r.push(l.top());
                l.pop();
            }
            while(!r.empty()&&r.top()[1]<data[i])r.pop();
            if(r.size()%2==1)n--;
        }
        printf("%d\n",n);
    }

}
