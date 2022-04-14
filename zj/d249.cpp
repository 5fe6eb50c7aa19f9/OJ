#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
char S[260];
char T[260];
char res[260];
int lcs[260][260];
char p[260][260];
int main(){
    int i,j,k,ssize,tsize,ans=0;
    scanf("%s %s",S+1,T+1);
    k=ssize=strlen(S+1);
    tsize=strlen(T+1);
    while(k--){
        for(i=1;i<=ssize;i++){
            for(j=1;j<=tsize;j++){
                if(S[i]==T[j]&&lcs[i-1][j-1]+1>lcs[i-1][j]&&lcs[i-1][j-1]+1>lcs[i][j-1]){
                    lcs[i][j]=lcs[i-1][j-1]+1;
                    p[i][j]=0;
                }else{
                    if(lcs[i-1][j]>=lcs[i][j-1]){
                        lcs[i][j]=lcs[i-1][j];
                        p[i][j]=1;
                    }else{
                        lcs[i][j]=lcs[i][j-1];
                        p[i][j]=2;
                    }
                }
            }
        }
        if(ans<lcs[ssize][tsize]){
            ans=lcs[ssize][tsize];
            res[ans+1]=0;
            for(i=ssize,j=tsize;i>0&&j>0;){
                switch(p[i][j]){
                case 0:
                    res[lcs[i][j]]=S[i],i--,j--;
                    break;
                case 1:
                    i--;
                    break;
                case 2:
                    j--;
                }
            }
        }
        for(i=1;i<=ssize;i++){
            for(j=1;j<=tsize;j++){
                lcs[i][j]=0;
            }
        }
        j=S[1];
        for(i=1;i<ssize;i++){
            S[i]=S[i+1];
        }
        S[i]=j;
    }
    if(ans==0){
        printf("no\n0.00\n");
        return 0;
    }
    printf("%s\n%.2lf\n",res+1,(double)ans*2/(ssize+tsize));
}
