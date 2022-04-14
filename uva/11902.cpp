#include <iostream>
#include <cstdio>
using namespace std;

bool ori[100];
bool res[100];
bool ans[100][100];
bool adj[100][100];
int n;
void dfs(int i){
    ori[i]=1;
    for(int j=0;j<n;j++){
        if(adj[i][j]&&!ori[j]){
            dfs(j);
        }
    }
}
void sol(int i,int dom){
    res[i]=1;
    for(int j=0;j<n;j++){
        if(adj[i][j]&&j!=dom&&!res[j]){
            sol(j,dom);
        }
    }
}
int main(){
    int T,t,i,j;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            ori[i]=0;
            for(j=0;j<n;j++){
                ans[i][j]=0;
                scanf("%d",adj[i]+j);
            }
        }
        dfs(0);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)res[j]=0;
            if(i!=0)sol(0,i);
            for(j=0;j<n;j++){
                if(ori[j]!=res[j]){
                    ans[i][j]=1;
                }
            }
        }
        printf("Case %d:\n+",t);
        for(j=0;j<n-1;j++){
            printf("--");
        }
        printf("-+\n");
        for(i=0;i<n;i++){
            printf("|");
            for(j=0;j<n;j++){
                if(ans[i][j]){
                    printf("Y|");
                }else{
                    printf("N|");
                }
            }
            printf("\n+");
            for(j=0;j<n-1;j++){
                printf("--");
            }
            printf("-+\n");
        }
    }
}
