#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
char direct[]={'W','N','E','S'};
bool g[60][60];
char cmd[110];
int main(){
    int i,j,k,r,c;
    int x,y,d;
    char tmp;
    while(scanf("%d %d",&r,&c)==2){
        for(i=0;i<=r;i++){
            for(j=0;j<=c;j++){
                g[i][j]=0;
            }
        }
        while(scanf("%d %d %c",&x,&y,&tmp)==3){
            switch(tmp){
            case 'N':
                d=1;
                break;
            case 'E':
                d=2;
                break;
            case 'S':
                d=3;
                break;
            case 'W':
                d=0;
                break;
            }
            scanf("%s",cmd);
            for(i=0;;i++){
                if(!cmd[i]){
                    printf("%d %d %c\n",x,y,direct[d]);
                    break;
                }
                if(cmd[i]=='L'){
                    d--;
                    if(d<0)d+=4;
                }else if(cmd[i]=='R'){
                    d++;
                    d%=4;
                }else{
                    x+=dx[d];
                    y+=dy[d];
                    if(x<0||x>r||y<0||y>c){
                        x-=dx[d];
                        y-=dy[d];
                        if(g[x][y])continue;
                        g[x][y]=1;
                        printf("%d %d %c LOST\n",x,y,direct[d]);
                        break;
                    }
                }
            }
        }
    }
}
