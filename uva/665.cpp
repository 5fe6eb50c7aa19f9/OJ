#include <cstdio>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

set<int> s[100][2];
string op[100];
set<int> ans;
int main(){
    int t,n,m,i,j,k,tmp;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++){
            scanf("%d",&j);
            s[i][0].clear(),s[i][1].clear();
            for(k=0;k<j;k++){
                scanf("%d",&tmp);
                s[i][0].insert(tmp);
            }
            for(k=0;k<j;k++){
                scanf("%d",&tmp);
                s[i][1].insert(tmp);
            }
            cin>>op[i];
        }
        ans.clear();
        for(i=1;i<=n;i++){
            for(j=0;j<m;j++){
                if(op[j]=="="){
                    if(s[j][0].find(i)!=s[j][0].end()||s[j][1].find(i)!=s[j][1].end())break;
                }else if(op[j]=="<"){
                    if(s[j][0].find(i)==s[j][0].end())break;
                }else{
                    if(s[j][1].find(i)==s[j][1].end())break;
                }
                if(j==m-1)ans.insert(i);
            }
            for(j=0;j<m;j++){
                if(op[j]=="="){
                    if(s[j][0].find(i)!=s[j][0].end()||s[j][1].find(i)!=s[j][1].end())break;
                }else if(op[j]=="<"){
                    if(s[j][1].find(i)==s[j][1].end())break;
                }else{
                    if(s[j][0].find(i)==s[j][0].end())break;
                }
                if(j==m-1)ans.insert(i);
            }
        }
        if(ans.size()==1){
            printf("%d\n",*(ans.begin()));
        }else{
            printf("0\n");
        }
        if(t)printf("\n");
    }
}
