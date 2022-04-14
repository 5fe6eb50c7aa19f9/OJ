#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int data[25];
stack<int> s[25];
stack<int> s2;
void dfs(int i){
    if(s[i].empty())return;
    int tmp=s[i].top();
    s[i].pop();
    dfs(i);
    printf(" %d",tmp);
}
int main(){
    int n,i,a,b,tmp;
    char cmd[10];
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++){
            data[i]=i;
            s[i].push(i);
        }
        while(scanf("%s",cmd)==1){
            if(cmd[0]=='m'){
                scanf("%d %s %d",&a,cmd,&b);
                if(a==b||data[a]==data[b])continue;
                while(s[data[a]].top()!=a){
                    tmp=s[data[a]].top();
                    s[data[a]].pop();
                    s[tmp].push(tmp);
                    data[tmp]=tmp;
                }
                if(cmd[1]=='n'){
                    while(s[data[b]].top()!=b){
                        tmp=s[data[b]].top();
                        s[data[b]].pop();
                        s[tmp].push(tmp);
                        data[tmp]=tmp;
                    }
                }
                s[data[a]].pop();
                s[data[b]].push(a);
                data[a]=data[b];
            }else if(cmd[0]=='p'){
                scanf("%d %s %d",&a,cmd,&b);
                if(a==b||data[a]==data[b])continue;
                if(cmd[1]=='n'){
                    while(s[data[b]].top()!=b){
                        tmp=s[data[b]].top();
                        s[data[b]].pop();
                        s[tmp].push(tmp);
                        data[tmp]=tmp;
                    }
                }
                while(1){
                    s2.push(s[data[a]].top());
                    s[data[a]].pop();
                    if(s2.top()==a)break;
                }
                while(!s2.empty()){
                    tmp=s2.top();
                    s2.pop();
                    s[data[b]].push(tmp);
                    data[tmp]=data[b];
                }
            }else{
                break;
            }
        }
        for(i=0;i<n;i++){
            printf("%d:",i);
            dfs(i);
            printf("\n");
        }
    }
}
