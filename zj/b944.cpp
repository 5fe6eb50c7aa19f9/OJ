#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)==1){
        int data[n+2][2];
        for(int i=0;i<n+2;i++)data[i][1]=0;
        int a,b;
        while(scanf("%d %d",&a,&b)==2){
            for(int i=1;i<=n;i++)data[i][1]--;
            int test=-1;
            bool flag=false;
            for(int i=1;i<=n;i++){
                if(data[i][1]<=0&&data[i-1][1]<=0&&data[i+1][1]<=0){
                    data[i][0]=a;
                    data[i][1]=b;
                    flag=true;
                    test=i;
                    break;
                }
            }
            if(!flag){
                for(int i=1;i<=n;i++){
                    if(data[i][1]<=0){
                        data[i][0]=a;
                        data[i][1]=b;
                        flag=true;
                        test=i;
                        break;
                    }
                }
            }
            if(!flag)printf("  Not enough\n");
            printf("Number:");
            for(int i=1;i<=n;i++){
                if(i==test){
                    printf(" %d",a);
                    continue;
                }
                if(data[i][1]<=0){
                    printf(" 0");
                }else{
                    printf(" %d",data[i][0]);
                }
            }
            printf("\n  Time:");
            for(int i=1;i<=n;i++){
                if(data[i][1]<=0){
                    printf(" 0");
                }else{
                    printf(" %d",data[i][1]);
                }
            }
            printf("\n\n");
        }
    }
}
