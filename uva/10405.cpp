#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int lcs[1001][1001];
string a,b;
int main(){
    int i,j;
    while(getline(cin,a)){
        getline(cin,b);
        for(i=0;i<a.size();i++){
            for(j=0;j<b.size();j++){
                if(a[i]==b[j]){
                    lcs[i+1][j+1]=lcs[i][j]+1;
                }else{
                    lcs[i+1][j+1]=max(lcs[i][j+1],lcs[i+1][j]);
                }
            }
        }
        printf("%d\n",lcs[a.size()][b.size()]);
    }
}
