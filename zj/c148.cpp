#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
int maze[1000][200];
struct cmp{
    bool operator()(const pair<int,int> one,const pair<int,int> two){
        return one.first>two.first;
    }
};
int main(){
    int row,col,x,y,n,m,b,e,k;
    int inf=1000000000;
    while(scanf("%d %d %d %d %d",&n,&m,&b,&e,&k)==5){
        for(row=0;row<n;row++){
            for(col=0;col<m;col++){
                maze[row][col]=inf;
            }
        }
        while(k>0){
            scanf("%d %d",&x,&y);
            maze[x][y]=-1;
            k--;
        }
        priority_queue< pair<int,int> ,vector< pair<int,int> >,cmp> next;//change col
        next.push(make_pair(0,b));
        for(row=0;row<n-1;row++){
            while(!next.empty()){
                if(maze[row][next.top().second]==inf){
                    maze[row][next.top().second]=next.top().first;
                    for(col=next.top().second+1;col<m&&maze[row][col]!=-1;col++)maze[row][col]=next.top().first+2;
                    for(col=next.top().second-1;col>=0&&maze[row][col]!=-1;col--)maze[row][col]=next.top().first+2;
                }else{
                    if(maze[row][next.top().second]>next.top().first){
                        maze[row][next.top().second]=next.top().first;
                    }
                }
                next.pop();
            }
            for(col=0;col<m;col++){
                if(maze[row][col]!=-1&&maze[row][col]!=inf){
                    next.push(make_pair(maze[row][col],col));
                }
            }
        }
        while(!next.empty()){
            if(maze[row][next.top().second]==inf){
                maze[row][next.top().second]=next.top().first;
                for(col=next.top().second+1;col<m&&maze[row][col]!=-1;col++)maze[row][col]=next.top().first+1;
                for(col=next.top().second-1;col>=0&&maze[row][col]!=-1;col--)maze[row][col]=next.top().first+1;
            }else{
                if(maze[row][next.top().second]>next.top().first){
                    maze[row][next.top().second]=next.top().first;
                }
            }
            next.pop();
        }
        printf("%d\n",maze[n-1][e]);
    }
}
