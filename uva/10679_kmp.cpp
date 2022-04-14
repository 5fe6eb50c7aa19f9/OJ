#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

char str[100001];
char sstr[1001];
int kmp[1001];
int main(){
    int T,t,i,j;
    kmp[0]=-1;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str);
        scanf("%d",&t);
        while(t--){
            scanf("%s",sstr);
            for(i=1,j=-1;sstr[i];i++){
                while(j!=-1&&sstr[i]!=sstr[j+1]){
                    j=kmp[j];
                }
                if(sstr[i]==sstr[j+1])j++;
                kmp[i]=j;
            }
            for(i=0,j=-1;str[i];i++){
                while(j!=-1&&str[i]!=sstr[j+1]){
                    j=kmp[j];
                }
                if(str[i]==sstr[j+1])j++;
                if(!sstr[j+1])break;
            }
            if(!sstr[j+1]){
                printf("y\n");
            }else{
                printf("n\n");
            }
        }
    }
}
