#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int num[26];
int ans[26];
bool cmp(int a,int b){
    if(num[a]!=num[b])return num[a]>num[b];
    return a<b;
}
int main(){
    int n,i;
    string data;
    for(i=0;i<26;i++)ans[i]=i;
    while(scanf("%d",&n)==1){
        getline(cin,data);
        memset(num,0,sizeof(num));
        while(n--){
            getline(cin,data);
            for(i=0;i<data.size();i++){
                if(data[i]>='a'&&data[i]<='z'){
                    num[data[i]-'a']++;
                }else if(data[i]>='A'&&data[i]<='Z'){
                    num[data[i]-'A']++;
                }
            }
        }
        sort(ans,ans+26,cmp);
        for(i=0;i<26;i++){
            if(num[ans[i]]==0)break;
            printf("%c %d\n",ans[i]+'A',num[ans[i]]);
        }
    }
}
