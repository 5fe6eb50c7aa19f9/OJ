#include <cstdio>
#include <iostream>
using namespace std;
string data;
int main(){
    int T,t,n,i,j;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d",&n);
        getline(cin,data);
        getline(cin,data);
        for(i=0,j=0;i<n;i++){
            if(data[i]=='.'){
                j++;
                i+=2;
            }
        }
        printf("Case %d: %d\n",t,j);
    }
}
