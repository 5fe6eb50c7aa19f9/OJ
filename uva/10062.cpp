#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int ascii[128];
int ans[128];
string s;
bool cmp(int &a,int &b){
    if(ascii[a]!=ascii[b]){
        return ascii[a]<ascii[b];
    }
    return a>b;
}
int main(){
    int t=0,i,n;
    while(getline(cin,s)){
        if(t++)printf("\n");
        memset(ascii,0,sizeof(ascii));
        n=0;
        for(i=0;i<s.size();i++){
            if(ascii[s[i]]==0){
                ans[n++]=s[i];
            }
            ascii[s[i]]++;
        }
        sort(ans,ans+n,cmp);
        for(i=0;i<n;i++){
            printf("%d %d\n",ans[i],ascii[ans[i]]);
        }
    }
}
