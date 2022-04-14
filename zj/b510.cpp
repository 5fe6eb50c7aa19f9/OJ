#include <iostream>
using namespace std;

int m,n,sum;
char data[10][10];
bool judge(char target,int x,int y,int dx,int dy){
    if(x<0||y<0||y>=m+n)return false;
    if(data[x][y]==target)return true;
    return judge(target,x+dx,y+dy,dx,dy);
}
void go(int x,int y,int q,int c){
    if(x==m+n){
        if(q==m&&c==n){
            sum++;
        }
        return;
    }
    bool flag=false;
    if(judge('c',x-1,y,-1,0)||judge('q',x-1,y,-1,0))flag=true;
    if(judge('q',x-1,y-1,-1,-1))flag=true;
    if(judge('q',x-1,y+1,-1,1))flag=true;
    if(!flag&&c<3){
        data[x][y]='c';
        go(x+1,0,q,c+1);
    }
    if(judge('c',x-1,y-1,-1,-1))flag=true;
    if(judge('c',x-1,y+1,-1,1))flag=true;
    if(!flag&&q<m){
        data[x][y]='q';
        go(x+1,0,q+1,c);
    }
    data[x][y]='0';
    if(y+1<n+m)go(x,y+1,q,c);
    return;
}
int main(){
    while(cin>>m>>n){
        sum=0;
        for(int i=0;i<m+n;i++){
            for(int j=0;j<m+n;j++)data[i][j]='0';
        }
        go(0,0,0,0);
        cout<<sum<<endl;
    }
}
