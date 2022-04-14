#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
char data[512][512];
int a,b,w,n,e,s,A;
void go(int x,int y){
    data[x][y]='0';
    A++;
    if(x>s)s=x;
    if(y>e)e=y;
    if(y<w)w=y;

    if(x-1>=0&&data[x-1][y]=='1')go(x-1,y);
    if(x+1<a&&data[x+1][y]=='1')go(x+1,y);
    if(y-1>=0&&data[x][y-1]=='1')go(x,y-1);
    if(y+1<b&&data[x][y+1]=='1')go(x,y+1);
}
int main(){
    while(cin>>a>>b){
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++)cin>>data[i][j];
        }
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(data[i][j]=='1'){
                    w=j;
                    n=i;
                    e=j;
                    s=i;
                    A=0;
                    go(i,j);
                    printf("%d %d %d %d %d\n",w,n,e,s,A);
                }
            }
        }
    }
}
