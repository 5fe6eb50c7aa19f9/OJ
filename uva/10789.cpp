#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool sieve[2001];
int ascii[128];
int main(){
    int t,T,i,j;
    bool flag;
    string data;
    for(i=2;i<=2000;i++){
        if(!sieve[i]){
            for(j=i*i;j<=2000;j+=i){
                sieve[j]=1;
            }
        }
    }
    scanf("%d",&T);
    getline(cin,data);
    for(t=1;t<=T;t++){
        getline(cin,data);
        memset(ascii,0,sizeof(ascii));
        for(i=0;i<data.size();i++){
            ascii[data[i]]++;
        }
        printf("Case %d: ",t);
        flag=0;
        for(i=0;i<128;i++){
            if(ascii[i]>1&&!sieve[ascii[i]]){
                flag=1;
                printf("%c",i);
            }
        }
        if(!flag)printf("empty");
        printf("\n");
    }
}
