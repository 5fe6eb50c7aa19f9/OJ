#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
char buf1[80000000];
char buf2[80000000];
int pos1,pos2;
bool cnt1[6500001];
bool cnt2[6500001];
inline int getint1(){
    int ret=0;
    while(buf1[pos1]>='0'&&buf1[pos1]<='9'){
        ret=ret*10+buf1[pos1++]-'0';
    }
    pos1++;
    return ret;
}
inline int getint2(){
    int ret=0;
    while(buf2[pos2]>='0'&&buf2[pos2]<='9'){
        ret=ret*10+buf2[pos2++]-'0';
    }
    pos2++;
    return ret;
}
int main(){
    int n,i,j,k,tmp,ans=0;
    scanf("%d\n",&n);
    scanf("%[^\n]\n",buf1);
    scanf("%[^\n]\n",buf2);
    pos1=pos2=0;
    for(i=0,j=0,k=0;i<n;i++){
        tmp=getint1();
        if(cnt2[tmp]){
            k--;
        }else{
            j++;
            cnt1[tmp]=1;
        }
        tmp=getint2();
        if(cnt1[tmp]){
            j--;
        }else{
            k++;
            cnt2[tmp]=1;
        }
        ans=max(ans,max(j,k));
    }
    printf("%d\n",ans+1);
}
