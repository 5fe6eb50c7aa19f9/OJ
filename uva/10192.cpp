#include <cstdio>
#include <iostream>
using namespace std;
int ans[101][101];
int main(){
    string f,m;
    int i,j,Case=1;
    while(getline(cin,f)&&f!="#"&&getline(cin,m)){
        for(i=1;i<=f.size();i++){
            for(j=1;j<=m.size();j++){
                ans[i][j]=0;
            }
        }
        for(i=0;i<f.size();i++){
            for(j=0;j<m.size();j++){
                if(f[i]==m[j]){
                    ans[i+1][j+1]=ans[i][j]+1;
                }else{
                    ans[i+1][j+1]=max(ans[i][j+1],ans[i+1][j]);
                }
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n",Case++,ans[f.size()][m.size()]);
    }
}
