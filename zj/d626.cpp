#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
char data[100][100];
void go(int x,int y,int n){
    data[x][y]='+';
    if(x-1>=0&&data[x-1][y]=='-')go(x-1,y,n);
    if(x+1<n&&data[x+1][y]=='-')go(x+1,y,n);
    if(y-1>=0&&data[x][y-1]=='-')go(x,y-1,n);
    if(y+1<n&&data[x][y+1]=='-')go(x,y+1,n);
    return;
}
int main(){
    int n;
    while(cin>>n){
        cin.ignore();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cin>>data[i][j];
        }
        int x,y;
        cin>>x>>y;
        go(x,y,n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<data[i][j];
            }
            cout<<endl;
        }
    }
}
