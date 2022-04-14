#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string s[3][3];
int main(){
    int t,i,j,k;
    scanf("%d%*c",&t);
    while(t--){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++)cin>>s[i][j];
        }
        for(k='A';k<='L';k++){
            for(i=0;i<3;i++){
                if(s[i][2][0]=='e'){
                    if(s[i][0].find(k)!=string::npos||s[i][1].find(k)!=string::npos)break;
                }else if(s[i][2][0]=='u'){
                    if(s[i][1].find(k)==string::npos)break;
                }else{
                    if(s[i][0].find(k)==string::npos)break;
                }
                if(i==2){
                    printf("%c is the counterfeit coin and it is light.\n",k);
                }
            }
            for(i=0;i<3;i++){
                if(s[i][2][0]=='e'){
                    if(s[i][0].find(k)!=string::npos||s[i][1].find(k)!=string::npos)break;
                }else if(s[i][2][0]=='u'){
                    if(s[i][0].find(k)==string::npos)break;
                }else{
                    if(s[i][1].find(k)==string::npos)break;
                }
                if(i==2){
                    printf("%c is the counterfeit coin and it is heavy.\n",k);
                }
            }
        }
    }
}
