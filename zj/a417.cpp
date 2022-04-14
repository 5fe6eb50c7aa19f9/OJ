#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a;
    while(cin>>a){
        int data[a][2];
        for(int i=0;i<a;i++){
            cin>>data[i][0]>>data[i][1];
        }
        for(int i=0;i<a;i++){
            int tmp[(data[i][0])][(data[i][0])];
            for(int r=0;r<data[i][0];r++){
                for(int c=0;c<data[i][0];c++){
                    tmp[r][c]=0;
                }
            }
            if(data[i][1]==1){
                for(int num=1,r=0,c=0;num<=data[i][0]*data[i][0];){
                    while(c<data[i][0]&&tmp[r][c]==0){
                        tmp[r][c]=num;
                        num++;
                        c++;
                    }
                    c--;
                    r++;
                    while(r<data[i][0]&&tmp[r][c]==0){
                        tmp[r][c]=num;
                        num++;
                        r++;
                    }
                    r--;
                    c--;
                    while(c>=0&&tmp[r][c]==0){
                        tmp[r][c]=num;
                        num++;
                        c--;
                    }
                    c++;
                    r--;
                    while(tmp[r][c]==0){
                        tmp[r][c]=num;
                        num++;
                        r--;
                    }
                    r++;
                    c++;
                }
            }else{
                for(int num=1,r=0,c=0;num<=data[i][0]*data[i][0];){
                    while(r<data[i][0]&&tmp[r][c]==0){
                        tmp[r][c]=num;
                        num++;
                        r++;
                    }
                    r--;
                    c++;
                    while(c<data[i][0]&&tmp[r][c]==0){
                        tmp[r][c]=num;
                        num++;
                        c++;
                    }
                    c--;
                    r--;
                    while(r>=0&&tmp[r][c]==0){
                        tmp[r][c]=num;
                        num++;
                        r--;
                    }
                    r++;
                    c--;
                    while(tmp[r][c]==0){
                        tmp[r][c]=num;
                        num++;
                        c--;
                    }
                    c++;
                    r++;
                }
            }
            for(int r=0;r<data[i][0];r++){
                for(int c=0;c<data[i][0];c++){
                    printf("%5d",tmp[r][c]);
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }
}
