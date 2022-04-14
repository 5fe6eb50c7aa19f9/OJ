#include <cstdio>
#include <iostream>
using namespace std;
struct node{
    int x,y;
    bool turn;
    node* next;
};
bool cloth[102][102][3];
int main(){
    int i,j,Now,Max,n,x,y;
    char target;
    bool targetjud[3];
    string buf;
    bool turn;
    int dx[]={-1,1,0,0,-1,-1,1,1};
    int dy[]={0,0,-1,1,-1,1,-1,1};
    node* Rf=0;
    node* Rr=0;
    node* Bf=0;
    node* Br=0;
    node* Yf=0;
    node* Yr=0;

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
            node* tmp=new node;
            tmp->x=n-x;
            tmp->y=y+1;
            tmp->turn=0;
            tmp->next=0;
            switch(target){
                case 'R':
                    Rf=tmp;
                    Rr=tmp;
                    break;
                case 'B':
                    Bf=tmp;
                    Br=tmp;
                    break;
                case 'Y':
                    Yf=tmp;
                    Yr=tmp;
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
        while(Rf||Bf||Yf){
            while(Rf&&Rf->turn==turn){
                if(cloth[Rf->x][Rf->y][0]){
                    if(targetjud[0]==cloth[Rf->x][Rf->y][0]&&targetjud[1]==cloth[Rf->x][Rf->y][1]&&targetjud[2]==cloth[Rf->x][Rf->y][2])Now--;
                    cloth[Rf->x][Rf->y][0]=0;
                    if(targetjud[0]==cloth[Rf->x][Rf->y][0]&&targetjud[1]==cloth[Rf->x][Rf->y][1]&&targetjud[2]==cloth[Rf->x][Rf->y][2])Now++;
                    for(i=0;i<8;i++){
                        if(!cloth[Rf->x+dx[i]][Rf->y+dy[i]][0])continue;
                        node* tmp=new node;
                        tmp->x=Rf->x+dx[i];
                        tmp->y=Rf->y+dy[i];
                        tmp->turn=!turn;
                        tmp->next=0;
                        Rr->next=tmp;
                        Rr=tmp;
                    }
                }
                node* del=Rf;
                Rf=Rf->next;
                delete del;
            }
            while(Bf&&Bf->turn==turn){
                if(cloth[Bf->x][Bf->y][1]){
                    if(targetjud[0]==cloth[Bf->x][Bf->y][0]&&targetjud[1]==cloth[Bf->x][Bf->y][1]&&targetjud[2]==cloth[Bf->x][Bf->y][2])Now--;
                    cloth[Bf->x][Bf->y][1]=0;
                    if(targetjud[0]==cloth[Bf->x][Bf->y][0]&&targetjud[1]==cloth[Bf->x][Bf->y][1]&&targetjud[2]==cloth[Bf->x][Bf->y][2])Now++;
                    for(i=0;i<8;i++){
                        if(!cloth[Bf->x+dx[i]][Bf->y+dy[i]][1])continue;
                        node* tmp=new node;
                        tmp->x=Bf->x+dx[i];
                        tmp->y=Bf->y+dy[i];
                        tmp->turn=!turn;
                        tmp->next=0;
                        Br->next=tmp;
                        Br=tmp;
                    }
                }
                node* del=Bf;
                Bf=Bf->next;
                delete del;
            }
            while(Yf&&Yf->turn==turn){
                if(cloth[Yf->x][Yf->y][2]){
                    if(targetjud[0]==cloth[Yf->x][Yf->y][0]&&targetjud[1]==cloth[Yf->x][Yf->y][1]&&targetjud[2]==cloth[Yf->x][Yf->y][2])Now--;
                    cloth[Yf->x][Yf->y][2]=0;
                    if(targetjud[0]==cloth[Yf->x][Yf->y][0]&&targetjud[1]==cloth[Yf->x][Yf->y][1]&&targetjud[2]==cloth[Yf->x][Yf->y][2])Now++;
                    for(i=0;i<8;i++){
                        if(!cloth[Yf->x+dx[i]][Yf->y+dy[i]][2])continue;
                        node* tmp=new node;
                        tmp->x=Yf->x+dx[i];
                        tmp->y=Yf->y+dy[i];
                        tmp->turn=!turn;
                        tmp->next=0;
                        Yr->next=tmp;
                        Yr=tmp;
                    }
                }
                node* del=Yf;
                Yf=Yf->next;
                delete del;
            }
            if(Now>Max)Max=Now;
            turn=!turn;
        }
        printf("%d\n",Max);
    }
}
