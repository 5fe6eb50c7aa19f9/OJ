#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int i,j,n,flag;
    int dp[81];
    dp[0]=-1;
    string data;
    scanf("%d",&n);
    getline(cin,data);
    while(n>0){
        n--;
        getline(cin,data);
        getline(cin,data);
        for(i=1,j=-1;i<data.size();i++){
            while(j!=-1&&data[i]!=data[j+1]){
                j=dp[j];
            }
            if(data[i]==data[j+1])j++;
            dp[i]=j;
        }
        flag=data.size()-1-dp[data.size()-1];
        if(data==""){
            printf("0\n");
        }else if(data.size()%flag==0){
            printf("%d\n",flag);
        }else{
            printf("%d\n",data.size());
        }
        if(n!=0)printf("\n");
    }
}
