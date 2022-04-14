#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;

char data[8];
char ans[8];
int main(){
    int a,b,i,j,k;
    while(scanf("%s %d %d",data,&a,&b)==3){
        for(i=0,j=0;data[i];i++){
            if(data[i]>='0'&&data[i]<='9'){
                j=j*a+data[i]-'0';
            }else{
                j=j*a+data[i]-'A'+10;
            }
            if(j>300000000)break;
        }
        if(j>300000000){
            printf("  ERROR\n");
            continue;
        }
        if(j==0){
            printf("      0\n");
            continue;
        }
        for(i=6;i>=0;i--){
            if(j==0){
                ans[i]=' ';
            }else{
                ans[i]=j%b;
                j/=b;
                if(ans[i]>=0&&ans[i]<=9){
                    ans[i]+='0';
                }else{
                    ans[i]+='A'-10;
                }
            }
        }
        if(j!=0){
            printf("  ERROR\n");
            continue;
        }
        printf("%s\n",ans);
    }
}
