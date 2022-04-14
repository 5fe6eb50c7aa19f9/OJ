#include <iostream>
#include <cstdio>
using namespace std;


int main(){
    int sat[101];
    for(int i=0;i<101;i++)sat[i]=0;
    int n;
    cin>>n;
    int food[n][2];
    bool used[n][101];//[0~n-1][0~100]
    for(int i=0;i<n;i++)cin>>food[i][0]>>food[i][1];
    for(int i=0;i<n;i++){
        for(int j=0;j<101;j++)used[i][j]=false;
    }
    for(int i=1;i<101;i++){//第i個飽足度
        int tmp=i-1;
        sat[i]=sat[tmp];
        int flag=-1;
        for(int j=0;j<n;j++){//第j個食物
            if(food[j][0]<=i&&sat[i-food[j][0]]+food[j][1]>sat[i]){
                if(used[j][i-food[j][0]]==false){//??
                    sat[i]=sat[i-food[j][0]]+food[j][1];
                    tmp=i-food[j][0];
                    flag=j;
                }
            }
        }
        if(flag!=-1)used[flag][i]=true;
        for(int j=0;j<n;j++){
            if(used[j][tmp])used[j][i]=true;
        }
    }
    cout<<sat[100]<<endl;
}
