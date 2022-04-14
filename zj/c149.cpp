#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int r,c;
    while(cin>>r>>c){
        char Map[r+2][c+2];
        bool record[r+2][c+2][8];
        for(int i=0;i<r+2;i++){
            string tmp;
            if(i>=1&&i<=r){
                cin>>tmp;
            }
            for(int j=0;j<c+2;j++){
                for(int k=0;k<8;k++)record[i][j][k]=false;
                if(i==0||i==r+1||j==0||j==c+1){
                    Map[i][j]=' ';
                }else{
                    Map[i][j]=tmp[j-1];
                }
            }
        }
        int x,y,d;
        string tmp;
        bool finish=false;
        while(cin>>y>>x>>tmp){
            if(tmp=="E"){
                d=0;
            }else if(tmp=="N"){
                d=90;
            }else if(tmp=="W"){
                d=180;
            }else if(tmp=="S"){
                d=270;
            }else if(tmp=="NE"){
                d=45;
            }else if(tmp=="SE"){
                d=315;
            }else if(tmp=="SW"){
                d=225;
            }else if(tmp=="NW"){
                d=135;
            }
            string mo;
            cin>>mo;
            if(finish){
                cout<<"I think I don't need to move anymore.\n";
                continue;
            }
            bool bad=false;
            for(int i=0;i<mo.size();){
                if(mo[i]=='R'||mo[i]=='L'){
                    bool flag=false;
                    if(mo[i]=='R')flag=true;
                    int change=0;
                    for(i=i+1;i<mo.size()&&mo[i]>='0'&&mo[i]<='9';i++){
                        change*=10;
                        change+=mo[i]-'0';
                    }
                    if(flag){
                        d-=change;
                    }else{
                        d+=change;
                    }
                    while(d<0)d+=360;
                    while(d>=360)d-=360;
                }else{
                    i++;
                    int tmpx=x,tmpy=y,tmpd;
                    if(d==0&&!record[x][y][0]){
                        y++;
                        tmpd=0;
                    }else if(d==45&&!record[x][y][1]){
                        x--;
                        y++;
                        tmpd=1;
                    }else if(d==90&&!record[x][y][2]){
                        x--;
                        tmpd=2;
                    }else if(d==135&&!record[x][y][3]){
                        x--;
                        y--;
                        tmpd=3;
                    }else if(d==180&&!record[x][y][4]){
                        y--;
                        tmpd=4;
                    }else if(d==225&&!record[x][y][5]){
                        x++;
                        y--;
                        tmpd=5;
                    }else if(d==270&&!record[x][y][6]){
                        x++;
                        tmpd=6;
                    }else if(d==315&&!record[x][y][7]){
                        x++;
                        y++;
                        tmpd=7;
                    }
                    if(Map[x][y]=='T'){
                        finish=true;
                        break;
                    }
                    if(Map[x][y]=='H'||x==0||x==r+1||y==0||y==c+1){
                        record[tmpx][tmpy][tmpd]=true;
                        x=tmpx;
                        y=tmpy;
                        bad=true;
                        break;
                    }
                }
            }
            cout<<y<<' '<<x<<' ';
            if(finish){
                cout<<"FINISHED!\n";
                continue;
            }
            if(d==0){
                cout<<"E ";
            }else if(d==45){
                cout<<"NE ";
            }else if(d==90){
                cout<<"N ";
            }else if(d==135){
                cout<<"NW ";
            }else if(d==180){
                cout<<"W ";
            }else if(d==225){
                cout<<"SW ";
            }else if(d==270){
                cout<<"S ";
            }else if(d==315){
                cout<<"SE ";
            }
            if(bad)cout<<"BAD PLAN!";
            cout<<endl;
        }
    }
}
