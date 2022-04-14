#include <cstdio>
#include <iostream>
using namespace std;

string s[105];//array size 100 will RE
int n=0;
int limit=0;
int main(){
    while(getline(cin,s[n])){
        if(s[n].size()>limit)limit=s[n].size();
        n++;
    }
    for(int i=0;i<limit;i++){
        for(int j=n-1;j>=0;j--){
            if(s[j].size()>i&&s[j][i]=='\t')continue;
            if(s[j].size()>i)printf("%c",s[j][i]);
            else printf(" ");
        }
        printf("\n");
    }
}
