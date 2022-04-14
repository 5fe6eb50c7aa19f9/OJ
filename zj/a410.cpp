#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a,b,c,A,B,C;
    while(scanf("%d %d %d %d %d %d",&a,&b,&c,&A,&B,&C)==6){
        int z=a*B-b*A,x=c*B-b*C,y=a*C-c*A;
        if(z==0&&x==0&&y==0){
            cout<<"Too many\n";
        }else if(z==0&&(x!=0||y!=0)){
            cout<<"No answer\n";
        }else{
            printf("x=%.2f\ny=%.2f\n",(float)x/(float)z,(float)y/(float)z);
        }
    }
}
