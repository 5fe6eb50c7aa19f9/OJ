#include <cstdio>
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

priority_queue<int> pq;
queue<int> tmp;
int main(){
    int n,i,j,flag;
    while(scanf("%d",&n)==1&&n){
        for(i=0;i<n;i++){
            scanf("%d",&j);
            if(j>0){
                pq.push(j);
            }
        }
        flag=0;
        while(!pq.empty()){
            i=pq.top();
            pq.pop();
            if(pq.size()<i){
                flag=1;
                while(!pq.empty())pq.pop();
            }else{
                while(i--){
                    j=pq.top()-1;
                    pq.pop();
                    if(j>0)tmp.push(j);
                }
                while(!tmp.empty()){
                    pq.push(tmp.front());
                    tmp.pop();
                }
            }
        }
        if(flag){
            printf("Not possible\n");
        }else{
            printf("Possible\n");
        }
    }
}
