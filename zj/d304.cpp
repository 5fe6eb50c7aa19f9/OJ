#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n;
char ans[10001];
char res[10001][6000];
int minl,num;
void dfs(int now,int ctrl,int i){
    if(i>minl)return;
    if(now>=n){
        if(now>n)return;
        ans[i]=0;
        if(i<minl){
            num=0;
            minl=i;
        }
        for(int j=0;j<=i;j++){
            res[num][j]=ans[j];
        }
        num++;
        return;
    }
    if(now!=ctrl){
        ans[i]='C';
        dfs(now,now,i+1);
    }
    ans[i]='V';
    dfs(now+ctrl,ctrl,i+1);
}
int main(){
    int i,j;
    ans[0]='C';
    while(scanf("%d",&n)==1){
        minl=0x7fffffff,num=1;
        dfs(1,1,1);
        printf("min : %d\nway : %d\n",minl,num);
        for(i=0;i<num;i++){
            printf("Ctrl C");
            for(j=1;res[i][j];j++){
                printf(" + %c",res[i][j]);
            }
            printf("\n");
        }
    }
}
