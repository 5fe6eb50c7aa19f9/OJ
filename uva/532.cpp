#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
struct node{
    int l,r,c;
    bool flag;
};
bool maze[32][32][32];
int main(){
    int l,r,c,i,j,k,sum;
    bool flag;
    int dl[]={-1,1,0,0,0,0};
    int dr[]={0,0,-1,1,0,0};
    int dc[]={0,0,0,0,-1,1};
    int E[3];
    string tmp;
    queue<node> bfs;
    while(scanf("%d %d %d",&l,&r,&c)==3&&!(l==0&&r==0&&c==0)){
        getline(cin,tmp);
        for(i=1;i<=l+1;i++){
            for(j=1;j<=r+1;j++){
                for(k=1;k<=c+1;k++){
                    if(i==l+1||j==r+1||k==c+1){
                        maze[i][j][k]=0;
                    }else{
                        maze[i][j][k]=1;
                    }
                }
            }
        }
        while(!bfs.empty())bfs.pop();
        for(i=1;i<=l;i++){
            for(j=1;j<=r;j++){
                getline(cin,tmp);
                for(k=1;k<=c;k++){
                    if(tmp[k-1]=='#'){
                        maze[i][j][k]=0;
                    }else if(tmp[k-1]=='S'){
                        node start;
                        start.l=i;
                        start.r=j;
                        start.c=k;
                        start.flag=0;
                        bfs.push(start);
                    }else if(tmp[k-1]=='E'){
                        E[0]=i;
                        E[1]=j;
                        E[2]=k;
                    }
                }
            }
            getline(cin,tmp);
        }
        flag=0;
        sum=0;
        while(!bfs.empty()&&maze[E[0]][E[1]][E[2]]){
            if(maze[bfs.front().l][bfs.front().r][bfs.front().c]){
                if(bfs.front().flag!=flag){
                    sum++;
                    flag=!flag;
                }
                maze[bfs.front().l][bfs.front().r][bfs.front().c]=0;
                for(i=0;i<6;i++){
                    if(maze[bfs.front().l+dl[i]][bfs.front().r+dr[i]][bfs.front().c+dc[i]]){
                        node next;
                        next.l=bfs.front().l+dl[i];
                        next.r=bfs.front().r+dr[i];
                        next.c=bfs.front().c+dc[i];
                        next.flag=!flag;
                        bfs.push(next);
                    }
                }
            }
            bfs.pop();
        }
        if(maze[E[0]][E[1]][E[2]]){
            printf("Trapped!\n");
        }else{
            printf("Escaped in %d minute(s).\n",sum);
        }
    }
}
