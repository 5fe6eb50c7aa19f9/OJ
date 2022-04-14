#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
    string name;
    int num;
    long double v;
};
node data[1000];
int ptr[1000];
bool cmp(int &a,int &b){
    if(data[a].num!=data[b].num)return data[a].num>data[b].num;
    if(data[a].v!=data[b].v)return data[a].v<data[b].v;
    return a<b;
}
int main(){
    int t=0,n,p,i,j;
    string tmp;
    while(scanf("%d %d",&n,&p)&&!(n==0&&p==0)){
        if(t>0)printf("\n");
        t++;
        getline(cin,tmp);
        for(i=0;i<n;i++)getline(cin,tmp);
        for(i=0;i<p;i++){
            getline(cin,data[i].name);
            scanf("%llf %d",&data[i].v,&data[i].num);
            getline(cin,tmp);
            for(j=0;j<data[i].num;j++)getline(cin,tmp);
            ptr[i]=i;
        }
        sort(ptr,ptr+p,cmp);
        printf("RFP #%d\n",t);
        cout<<data[ptr[0]].name<<endl;
    }
}
