#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int T,i,j,tmp;
    string data;
    scanf("%d",&T);
    getline(cin,data);
    while(T-->0){
        getline(cin,data);
        tmp=sqrt(data.size());
        if(tmp*tmp!=data.size()){
            printf("INVALID\n");
        }else{
            for(i=0;i<tmp;i++){
                for(j=0;j<tmp;j++){
                    printf("%c",data[j*tmp+i]);
                }
            }
            printf("\n");
        }
    }
}
