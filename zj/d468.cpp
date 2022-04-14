#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define ll long long

ll pow(ll a,ll n){
    ll ret=1;
    while(n){
        if(n&1)ret*=a;
        a*=a;
        n>>=1;
    }
    return ret;
}
string tmp;
int main(){
    ll a,n,ans;
    while(scanf("%lld",&a)){
        if(a==0||a==1||a==-1){
            getline(cin,tmp);
            if(a==0){
                if(tmp==" 0")break;
                ans=0;
            }else if(a==1){
                ans=1;
            }else{
                ans=1-2*((tmp[tmp.size()-1]-'0')%2==1);
            }
        }else{
            scanf("%lld",&n);
            ans=pow(a,n);
        }
        printf("%lld\n",ans);
    }
    printf("All Over.\n");
}
