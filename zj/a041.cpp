#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct node{
    int l,r;
};
bool cmp(node &a,node &b){
    return a.l<b.l;
}
struct cmpl{
    bool operator()(node &a,node &b){
        return a.l>b.l;
    }
};
struct cmpr{
    bool operator()(node &a,node &b){
        return a.r>b.r;
    }
};
priority_queue<node,vector<node>,cmpl> accept;
priority_queue<node,vector<node>,cmpr> failed;
node data[30000];
int main(){
    int n,y,i,j,placenum,availblenum;
    while(scanf("%d %d",&n,&y)==2){
        for(i=0;i<n;i++){
            scanf("%d %d",&data[i].l,&data[i].r);
        }
        sort(data,data+n,cmp);
        placenum=availblenum=0;
        while(!accept.empty())accept.pop();
        while(!failed.empty())failed.pop();
        for(i=1,j=-1;i<=100000-y;i++){
            while(!failed.empty()&&failed.top().r<=i+y){
                accept.push(failed.top());
                failed.pop();
            }
            while(!accept.empty()&&accept.top().l<i){
                accept.pop();
            }
            while(j+1<n&&data[j+1].l<=i+y){
                j++;
                if(data[j].r>i+y){
                    failed.push(data[j]);
                }else{
                    accept.push(data[j]);
                }
            }
            if(availblenum<accept.size()){
                placenum=1;
                availblenum=accept.size();
            }else if(availblenum==accept.size()){
                placenum++;
            }
        }
        printf("%d %d\n",placenum,availblenum);
    }
}
