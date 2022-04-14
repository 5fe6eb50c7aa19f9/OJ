#include <iostream>
#include <cstdio>
using namespace std;

int N;
char maze[100][100];
int pacerecord[100][100];

int go(int x,int y,int pace){
    if(x==N-2&&y==N-2){
        pacerecord[x][y]=pace;
        return 0;
    }
    maze[x][y]='@';
    pacerecord[x][y]=pace;
    int tmp=0;
    if(pacerecord[x][y+1]>pace+1&&maze[x][y+1]!='#'&&maze[x][y+1]!='@'){
        if(go(x,y+1,pace+1)==1){
            maze[x][y+1]='#';
        }else{
            maze[x][y+1]='.';
        }
    }
    if(pacerecord[x+1][y]>pace+1&&maze[x+1][y]!='#'&&maze[x+1][y]!='@'){
        if(go(x+1,y,pace+1)==1){
            maze[x+1][y]='#';
        }else{
            maze[x+1][y]='.';
        }
    }
    if(pacerecord[x-1][y]>pace+1&&maze[x-1][y]!='#'&&maze[x-1][y]!='@'){
        if(go(x-1,y,pace+1)==1){
            maze[x-1][y]='#';
        }else{
            maze[x-1][y]='.';
        }
    }
    if(pacerecord[x][y-1]>pace+1&&maze[x][y-1]!='#'&&maze[x][y-1]!='@'){
        if(go(x,y-1,pace+1)==1){
            maze[x][y-1]='#';
        }else{
            maze[x][y-1]='.';
        }
    }
    if(maze[x+1][y]=='#')tmp++;
    if(maze[x-1][y]=='#')tmp++;
    if(maze[x][y+1]=='#')tmp++;
    if(maze[x][y-1]=='#')tmp++;
    if(tmp==3){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    while(cin>>N){
        char test;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>maze[i][j];
                pacerecord[i][j]=0x7fffffff;
            }
        }
        go(1,1,1);
        if(pacerecord[N-2][N-2]==0x7fffffff){
            cout<<"No solution!\n";
        }else{
            cout<<pacerecord[N-2][N-2]<<endl;
        }
    }
}
