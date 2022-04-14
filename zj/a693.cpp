#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)==2){
        int serie[a];
        int data[b][2];
        for(int i=0;i<a;i++)scanf("%d",&serie[i]);
        for(int i=0;i<b;i++)scanf("%d %d",&data[i][0],&data[i][1]);
        for(int i=1;i<a;i++)serie[i]+=serie[i-1];
        for(int i=0;i<b;i++){
            if(data[i][0]-2<0){
                cout<<serie[data[i][1]-1]<<endl;
            }else{
                cout<<serie[data[i][1]-1]-serie[data[i][0]-2]<<endl;
            }
        }
    }
}
