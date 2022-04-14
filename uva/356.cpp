#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
bool ret[151][151];
int main(){
    int t=0,n,i,j,ins,hal;
    int dx,dy,r;
    while(scanf("%d",&n)==1){
        if(t++)printf("\n");
        r=n*10-5;
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                dx=(n-i)*10;
                dy=(n-j)*10;
                if(dx*dx+dy*dy>r*r){
                    ret[i][j]=0;
                }else if(dx*dx+dy*dy<r*r){
                    ret[i][j]=1;
                }else{
                    ret[i][j]=2;
                }
            }
        }
        ins=hal=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(ret[i][j]){
                    if(ret[i-1][j-1]){
                        ins++;
                    }else if(ret[i][j]!=2){
                        hal++;
                    }
                }
            }
        }
        printf("In the case n = %d, %d cells contain segments of the circle.\n",n,hal*4);
        printf("There are %d cells completely contained in the circle.\n",ins*4);
    }
}
