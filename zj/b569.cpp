#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

char str1[10000001];
char str2[10000001];
int main(){
    int n,i,j;
    scanf("%s %s",str1,str2);
    for(i=0,j=1;str1[i];i++){
        str2[i]=str1[i]!=str2[i];
        str2[i]+=j;
        j=0;
        if(str2[i]>1){
            str2[i]=0;
            j=1;
        }
        if(str2[i]){
            printf("%d",str1[i]=='0');
        }else{
            printf("%c",str1[i]);
        }
    }
    printf("\n");
}
