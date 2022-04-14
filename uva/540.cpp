#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int team[1000000];
queue<int> q[1000];
queue<int> p;
int main(){
    int c=0,t,i,j,k,num;
    char quest[100];
    while(scanf("%d",&t)==1&&t){
        c++;
        printf("Scenario #%d\n",c);
        for(i=0;i<t;i++){
            while(!q[i].empty())q[i].pop();
            scanf("%d",&k);
            for(j=0;j<k;j++){
                scanf("%d",&num);
                team[num]=i;
            }
        }
        while(!p.empty())p.pop();
        while(scanf("%s",quest)){
            if(quest[0]=='S'){
                break;
            }
            if(quest[0]=='E'){
                scanf("%d",&num);
                if(q[team[num]].empty()){
                    p.push(team[num]);
                    q[team[num]].push(num);
                }else{
                    q[team[num]].push(num);
                }
            }else{
                num=q[p.front()].front();
                q[p.front()].pop();
                if(q[p.front()].empty()){
                    p.pop();
                }
                printf("%d\n",num);
            }
        }
        printf("\n");
    }
}
