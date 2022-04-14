#include <cstdio>
#include <algorithm>
using namespace std;

float x[4],y[4];
int main(){
    int t,i,j;
    float coef,cons,res1,res2;
    scanf("%d",&t);
    printf("INTERSECTING LINES OUTPUT\n");
    while(t--){
        for(i=0;i<4;i++)scanf("%f %f",x+i,y+i);
        if((y[1]-y[0])*(x[3]-x[2])!=(y[3]-y[2])*(x[1]-x[0])){
            if(x[3]-x[2]==0){
                res1=x[3];
                res2=y[0]+(res1-x[0])*(y[1]-y[0])/(x[1]-x[0]);
            }else if(x[1]-x[0]==0){
                res1=x[1];
                res2=y[2]+(res1-x[2])*(y[3]-y[2])/(x[3]-x[2]);
            }else{
                coef=(y[3]-y[2])/(x[3]-x[2])-(y[1]-y[0])/(x[1]-x[0]);
                cons=y[0]-x[0]*(y[1]-y[0])/(x[1]-x[0])-y[2]+x[2]*(y[3]-y[2])/(x[3]-x[2]);
                res1=cons/coef;
                res2=y[0]+(res1-x[0])*(y[1]-y[0])/(x[1]-x[0]);
            }
            printf("POINT %.2f %.2f\n",res1,res2);
        }else{
            if((y[1]-y[0])*(x[3]-x[0])==(y[3]-y[0])*(x[1]-x[0])){
                printf("LINE\n");
            }else{
                printf("NONE\n");
            }
        }
    }
    printf("END OF OUTPUT\n");
}
