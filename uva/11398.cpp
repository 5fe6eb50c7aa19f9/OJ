#include <iostream>
#include <cstdio>
#include <unordered_set>
using namespace std;

int main(){
    int n,i,j;
    long long ans,flag;
    string tmp;
    while(cin>>tmp&&tmp!="~"){
        ans=0;
        flag=tmp.size()==1;
        while(cin>>tmp&&tmp!="#"){
            if(tmp.size()<=2){
                flag=tmp.size()==1;
            }else{
                for(i=0;i<tmp.size()-2;i++){
                    ans<<=1;
                    ans+=flag;
                }
            }
        }
        printf("%lld\n",ans);
    }
}
