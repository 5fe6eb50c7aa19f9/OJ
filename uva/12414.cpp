#include <iostream>
#include <cstdio>
using namespace std;
int data[10];
int num;
int tmp[50];
int tmp2[50];
int st;
bool go(){
    int i,j,k,l=0;
    for(i=0;i<num;i++){
        j=data[i]+st;
        k=0;
        while(j>0){
            tmp2[k++]=j%10;
            j/=10;
        }
        for(k=k-1;k>=0;k--){
            tmp[l++]=tmp2[k];
        }
    }
    for(i=l;i>2;i--){
        if(i==3&&tmp[0]==1&&tmp[1]==0&&tmp[2]==0)return 0;
        for(j=0;j<i-1;j++){
            tmp[j]=(tmp[j]+tmp[j+1])%10;
        }
    }
    return 1;
}
int main(){
    int i;
    string s;
    while(getline(cin,s)){
        num=0;
        for(i=0;i<s.size();i++){
            if(s[i]>='A'&&s[i]<='Z'){
                data[num++]=s[i]-'A';
            }
        }
        for(st=1;go()&&st<=10000;st++);
        if(st<=10000)printf("%d\n",st);
        else printf(":(\n");
    }
}
