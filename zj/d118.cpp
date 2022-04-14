#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

char str[50000000];
int strsize;
int main(){
    int n,i,j,flag,pos;
    while(scanf("%s %d",str,&n)==2){
        strsize=strlen(str);
        for(i=0;n>0;i=pos+1){
            flag=-1;
            for(j=i;j+n<=strsize;j++){
                if(flag<str[j]){
                    flag=str[j];
                    pos=j;
                }
                if(flag=='9')break;
            }
            printf("%c",flag);
            n--;
        }
        printf("\n");
    }
}
