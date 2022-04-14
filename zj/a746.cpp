#include <iostream>
#include <cstdio>
using namespace std;

char image[502][502];
int n,m;
void draw(int x1,int x2,int y1,int y2){
    if(x1==x2){
        if(y1>y2){
            int tmp=y1;
            y1=y2;
            y2=tmp;
        }
        for(;y1<=y2;y1++)image[x1][y1]='*';
        return;
    }else if(y1==y2){
        if(x1>x2){
            int tmp=x1;
            x1=x2;
            x2=tmp;
        }
        for(;x1<=x2;x1++)image[x1][y1]='*';
        return;
    }
}
int main()
{
    while(cin>>n>>m){
        for(int i=0;i<=n+1;i++){
            image[i][0]='|';
            image[i][n+1]='|';
            image[0][i]='-';
            image[n+1][i]='-';
        }
        image[n+1][0]='-';
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)image[i][j]=' ';
        }
        int data[m][2];
        for(int i=0;i<m;i++){
            cin>>data[i][0]>>data[i][1];
        }
        for(int i=1;i<m;i++){
            draw(data[i-1][0],data[i][0],data[i-1][1],data[i][1]);
        }
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=n+1;j++)cout<<image[i][j];
            cout<<endl;
        }
    }
}
