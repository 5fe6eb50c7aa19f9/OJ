#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

string data;
char ans[20];
bool flag[20];
void sol(int i){
    if(i==data.size()){
        ans[i]=0;
        printf("%s\n",ans);
        return;
    }
    ans[i]=0;
    for(int j=0;j<data.size();j++){
        if(!flag[j]&&data[j]!=ans[i]){
            ans[i]=data[j];
            flag[j]=1;
            sol(i+1);
            flag[j]=0;
        }
    }
}
int main(){
    int t,i,j;
    scanf("%d\n",&t);
    while(t--){
        getline(cin,data);
        sort(data.begin(),data.end());
        memset(flag,0,sizeof(flag));
        sol(0);
        printf("\n");
    }
}
