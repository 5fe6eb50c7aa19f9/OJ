#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

string tmp;
int ans[1005][256];
int main(){
    int n,m,i,j;
    while(scanf("%d %d",&n,&m)==2&&!(n==0&&m==0)){
        getline(cin,tmp);
        for(i=0;i<1005;i++)memset(ans[i],0,sizeof(ans[i]));
        for(i=0;i<n*m-1;i++){
            getline(cin,tmp);
            for(j=0;j<tmp.size();j++){
                ans[j][tmp[j]]++;
            }
        }
        for(i=0;i<1005;i++){
            for(j=0;j<256;j++){
                if(ans[i][j]%m!=0){
                    printf("%c",j);
                    break;
                }
            }
        }
        printf("\n");
    }
}
