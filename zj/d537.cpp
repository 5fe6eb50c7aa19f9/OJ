#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct node{
    int x,y;
    bool turn;
};
bool cloth[102][102][3];
int dx[]={-1,1,0,0,-1,-1,1,1};
int dy[]={0,0,-1,1,-1,1,-1,1};

int main(){
    queue<node> R,B,Y;
    while(!R.empty())R.pop();
    while(!B.empty())B.pop();
    while(!Y.empty())Y.pop();
    int i,j,Now,Max,n,x,y;
    char target;
    bool targetjud[3];
    string buf;
    bool turn;

    while(scanf("%d",&n)==1){
        getline(cin,buf);
        for(i=1;i<=n+1;i++){
            for(j=1;j<=n+1;j++){
                if(i==n+1||j==n+1){
                    cloth[i][j][0]=0,cloth[i][j][1]=0,cloth[i][j][2]=0;
                }else{
                    cloth[i][j][0]=1,cloth[i][j][1]=1,cloth[i][j][2]=1;
                }
            }
        }
        for(i=0;i<3;i++){
            scanf("%c %d %d",&target,&y,&x);
            getline(cin,buf);
            node tmp;
            tmp.x=x+1;
            tmp.y=y+1;
            tmp.turn=0;
            switch(target){
                case 'R':
                    R.push(tmp);
                    break;
                case 'B':
                    B.push(tmp);
                    break;
                case 'Y':
                    Y.push(tmp);
                    break;
            }
        }
        scanf("%c",&target);
        switch(target){
            case 'R':
                targetjud[0]=0,targetjud[1]=1,targetjud[2]=1;
                break;
            case 'B':
                targetjud[0]=1,targetjud[1]=0,targetjud[2]=1;
                break;
            case 'Y':
                targetjud[0]=1,targetjud[1]=1,targetjud[2]=0;
                break;
            case 'O':
                targetjud[0]=0,targetjud[1]=1,targetjud[2]=0;
                break;
            case 'P':
                targetjud[0]=0,targetjud[1]=0,targetjud[2]=1;
                break;
            case 'G':
                targetjud[0]=1,targetjud[1]=0,targetjud[2]=0;
                break;
            case 'D':
                targetjud[0]=0,targetjud[1]=0,targetjud[2]=0;
                break;
        }
        Now=0,Max=0,turn=0;
        while(!R.empty()||!B.empty()||!Y.empty()){
            while(!R.empty()&&R.front().turn==turn){
                if(cloth[R.front().x][R.front().y][0]){
                    if(targetjud[0]==cloth[R.front().x][R.front().y][0]&&targetjud[1]==cloth[R.front().x][R.front().y][1]&&targetjud[2]==cloth[R.front().x][R.front().y][2])Now--;
                    cloth[R.front().x][R.front().y][0]=0;
                    if(targetjud[0]==cloth[R.front().x][R.front().y][0]&&targetjud[1]==cloth[R.front().x][R.front().y][1]&&targetjud[2]==cloth[R.front().x][R.front().y][2])Now++;
                    for(i=0;i<8;i++){
                        if(!cloth[R.front().x+dx[i]][R.front().y+dy[i]][0])continue;
                        node tmp;
                        tmp.x=R.front().x+dx[i];
                        tmp.y=R.front().y+dy[i];
                        tmp.turn=!turn;
                        R.push(tmp);
                    }
                }
                R.pop();
            }
            while(!B.empty()&&B.front().turn==turn){
                if(cloth[B.front().x][B.front().y][1]){
                    if(targetjud[0]==cloth[B.front().x][B.front().y][0]&&targetjud[1]==cloth[B.front().x][B.front().y][1]&&targetjud[2]==cloth[B.front().x][B.front().y][2])Now--;
                    cloth[B.front().x][B.front().y][1]=0;
                    if(targetjud[0]==cloth[B.front().x][B.front().y][0]&&targetjud[1]==cloth[B.front().x][B.front().y][1]&&targetjud[2]==cloth[B.front().x][B.front().y][2])Now++;
                    for(i=0;i<8;i++){
                        if(!cloth[B.front().x+dx[i]][B.front().y+dy[i]][1])continue;
                        node tmp;
                        tmp.x=B.front().x+dx[i];
                        tmp.y=B.front().y+dy[i];
                        tmp.turn=!turn;
                        B.push(tmp);
                    }
                }
                B.pop();
            }
            while(!Y.empty()&&Y.front().turn==turn){
                if(cloth[Y.front().x][Y.front().y][2]){
                    if(targetjud[0]==cloth[Y.front().x][Y.front().y][0]&&targetjud[1]==cloth[Y.front().x][Y.front().y][1]&&targetjud[2]==cloth[Y.front().x][Y.front().y][2])Now--;
                    cloth[Y.front().x][Y.front().y][2]=0;
                    if(targetjud[0]==cloth[Y.front().x][Y.front().y][0]&&targetjud[1]==cloth[Y.front().x][Y.front().y][1]&&targetjud[2]==cloth[Y.front().x][Y.front().y][2])Now++;
                    for(i=0;i<8;i++){
                        if(!cloth[Y.front().x+dx[i]][Y.front().y+dy[i]][2])continue;
                        node tmp;
                        tmp.x=Y.front().x+dx[i];
                        tmp.y=Y.front().y+dy[i];
                        tmp.turn=!turn;
                        Y.push(tmp);
                    }
                }
                Y.pop();
            }
            if(Now>Max)Max=Now;
            turn=!turn;
        }
        printf("%d\n",Max);
    }
}
