#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
struct node{
    int i,v;
};
char buf[10000000];
int data[1000000];
int r[1000000];
stack<node> s;
int main(){
    int n,i,j;
    long long ans;
    while(scanf("%d\n",&n)==1){
        scanf("%[^\n]",buf);
        for(i=j=n=0;buf[i];i++){
            if(buf[i]==' '){
                data[n++]=j;
                j=0;
            }else{
                j=j*10+buf[i]-'0';
            }
        }
        data[n++]=j;
        while(!s.empty())s.pop();
        for(i=0;i<n;i++){
            while(!s.empty()&&s.top().v>=data[i]){
                s.pop();
            }
            if(s.empty()){
                r[i]=i+1;
            }else{
                r[i]=i-s.top().i;
            }
            s.push(node{i,data[i]});
        }
        while(!s.empty())s.pop();
        for(i=n-1;i>=0;i--){
            while(!s.empty()&&s.top().v>=data[i]){
                s.pop();
            }
            if(s.empty()){
                r[i]=min(r[i],n-i);
            }else{
                r[i]=min(r[i],s.top().i-i);
            }
            s.push(node{i,data[i]});
        }
        for(i=0,ans=0;i<n;i++){
            ans+=r[i];
        }
        printf("%lld\n",ans);
    }
}
