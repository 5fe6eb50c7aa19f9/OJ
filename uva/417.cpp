#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int C[27][5];
int main(){
    int i,j,k,ans;
    string str;
    C[0][0]=1;
    for(i=1;i<27;i++){
        for(j=0;j<=i&&j<5;j++){
            if(j==0){
                C[i][j]=1;
                continue;
            }
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    while(getline(cin,str)){
        ans=0;
        for(i=0;i<str.size();i++)ans+=C[26][i];
        for(i=0;i<str.size();i++){
            if(i>0){
                j=str[i-1]+1;
            }else{
                j='a';
            }
            if(j>str[i]){
                ans=0;
                break;
            }
            for(;j<str[i];j++){
                ans+=C['z'-j][str.size()-i-1];
            }
        }
        printf("%d\n",ans);
    }
}
