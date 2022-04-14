#include <iostream>
#include <cstdio>
using namespace std;
const int ori[3][3]={{1,1,1},{1,0,0},{0,1,0}};
int data[3][3];
void pow(){
    int tmp[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)tmp[i][j]=0;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                tmp[i][j]+=data[i][k]*data[k][j];
                tmp[i][j]%=10007;
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)data[i][j]=tmp[i][j];
    }
}
void go(int x){
    if(x==1||x==0)return;
    if(x%2==0){
        go(x/2);
        pow();
    }else{
        go(x/2);
        pow();
        int tmp[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)tmp[i][j]=0;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    tmp[i][j]+=data[i][k]*ori[k][j];
                    tmp[i][j]%=10007;
                }
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)data[i][j]=tmp[i][j];
        }
    }
    return;
}
int main(){
    int n;
    while(cin>>n){
        if(n==1||n==2||n==3){
            cout<<'1'<<endl;
        }else{
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++)data[i][j]=ori[i][j];
            }
            go(n-3);
            cout<<(data[0][0]+data[0][1]+data[0][2])%10007<<endl;
        }
    }
}
