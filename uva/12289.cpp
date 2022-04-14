#include <iostream>
#include <cstdio>
#include <unordered_set>
using namespace std;

string ans[9]={"one","two","three","four","five","six","seven","eight","nine"};
int main(){
    int n,i,j,wrong;
    string data;
    scanf("%d",&n);
    getline(cin,data);
    while(n--){
        getline(cin,data);
        for(i=0;i<9;i++){
            if(data.size()==ans[i].size()){
                for(j=wrong=0;wrong<2&&j<data.size();j++){
                    if(data[j]!=ans[i][j])wrong++;
                }
                if(wrong<2){
                    printf("%d\n",i+1);
                    break;
                }
            }
        }
    }
}
