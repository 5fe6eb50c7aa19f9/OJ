#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int secret[201];
int repeat[201][201];
int num[201];
string data;
string ans;
int main(){
    int n,i,j,k;
    while(scanf("%d",&n)==1&&n){
        for(i=0;i<n;i++){
            scanf("%d",secret+i);
            secret[i]--;
        }
        for(i=0;i<n;i++){
            repeat[i][0]=i;
            for(j=secret[i],k=1;j!=i;j=secret[j],k++){
                repeat[i][k]=j;
            }
            num[i]=k;
        }
        while(scanf("%d%*c",&k)==1&&k){
            getline(cin,data);
            while(data.size()<n)data+=" ";
            ans=data;
            for(i=0;i<data.size();i++){
                ans[repeat[i][k%num[i]]]=data[i];
            }
            cout<<ans<<endl;
        }
        printf("\n");
    }
}
