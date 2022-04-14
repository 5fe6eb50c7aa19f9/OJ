#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
string t,p;
int main(){
    int i,j,k,ans,pos;
    while(getline(cin,p)){
        getline(cin,t);
        ans=0,pos=0x7fffffff;
        for(i=0;i<t.size();){
            while(t[i]==' ')i++;
            for(j=0;;i++,j++){
                if(j==p.size()&&(i==t.size()||t[i]==' ')){
                    pos=min(pos,i-j);
                    ans++;
                    break;
                }
                if(i==t.size()||(t[i]!=p[j]&&(t[i]^32)!=p[j]))break;
            }
            while(i<t.size()&&t[i]!=' ')i++;
        }
        if(ans){
            printf("%d %d\n",ans,pos);
        }else{
            printf("-1\n");
        }
    }
}
