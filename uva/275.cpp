#include <cstdio>
#include <algorithm>
using namespace std;

int flag[10000000];
int main(){
    int n,m,i,j,k;
    while(scanf("%d %d",&n,&m)==2&&n+m){
        for(i=0;i<m;i++)flag[i]=-1;
        printf(".");
        j=1;
        while(flag[n]<0){
            flag[n]=j++;
            if(j%50==1)printf("\n");
            printf("%01d",n*10/m);
            n=n*10%m;
            if(!n)break;
        }
        printf("\n");
        if(n==0){
            printf("This expansion terminates.\n\n");
        }else{
            printf("The last %d digits repeat forever.\n\n",j-flag[n]);
        }
    }
}
