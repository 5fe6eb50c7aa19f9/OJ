#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)==2){
        int data[a][a];
        int eat[b][4];
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                scanf("%d",&data[i][j]);
                if(j>0)data[i][j]+=data[i][j-1];
            }
        }
        for(int i=0;i<b;i++){
            for(int j=0;j<4;j++)scanf("%d",&eat[i][j]);
        }
        for(int i=0;i<b;i++){
            int sum=0;
            for(int j=eat[i][0];j<=eat[i][2];j++){
                if(eat[i][1]>1){
                    sum+=data[j-1][eat[i][3]-1]-data[j-1][eat[i][1]-2];
                }else{
                    sum+=data[j-1][eat[i][3]-1];
                }
            }
            printf("%d\n",sum);
        }
    }
}
