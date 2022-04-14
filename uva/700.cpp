#include <cstdio>
#include <algorithm>
using namespace std;

int data[20][3];
int main(){
    int t=0,n,i,j,k;
    while(scanf("%d",&n)==1&&n){
        for(i=0;i<n;i++){
            for(j=0;j<3;j++){
                scanf("%d",data[i]+j);
            }
        }
        printf("Case #%d:\n",++t);
        for(i=0;i<10000;i++){
            for(j=k=0;j<n;j++){
                if(i<data[j][2]){
                    if(i!=data[j][0])break;
                }else{
                    if(data[j][1]+(i-data[j][2])%(data[j][2]-data[j][1])!=data[j][0])break;
                }
                if(j+1==n)k=1;
            }
            if(k==1){
                printf("The actual year is %d.\n\n",i);
                break;
            }
            if(i+1==10000){
                printf("Unknown bugs detected.\n\n");
            }
        }
    }
}
