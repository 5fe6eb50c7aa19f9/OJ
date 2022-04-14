#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

char data[8000000];
int cnt[1000001];
queue<long long> a,b;
int main(){
    int i,j,n;
    long long tmp,ans;
    while(scanf("%d",&n)==1&&n){
        memset(cnt,0,sizeof(cnt));
        while(!a.empty())a.pop();
        while(!b.empty())b.pop();
        ans=0;
        scanf("%c",&data[0]);
        scanf("%[^\n]",data);
        for(i=0,j=0;data[i];i++){
            if(data[i]==' '){
                cnt[j]++;
                j=0;
            }else{
                j=j*10+data[i]-'0';
            }
        }
        cnt[j]++;
        for(i=0;i<=1000000;i++){
            while(cnt[i]>0){
                cnt[i]--;
                a.push(i);
            }
        }
        while(a.size()+b.size()>1){
            if(a.empty()){
                tmp=b.front();
                b.pop();
            }else if(b.empty()){
                tmp=a.front();
                a.pop();
            }else if(a.front()<b.front()){
                tmp=a.front();
                a.pop();
            }else{
                tmp=b.front();
                b.pop();
            }
            if(a.empty()){
                tmp+=b.front();
                b.pop();
            }else if(b.empty()){
                tmp+=a.front();
                a.pop();
            }else if(a.front()<b.front()){
                tmp+=a.front();
                a.pop();
            }else{
                tmp+=b.front();
                b.pop();
            }
            ans+=tmp;
            b.push(tmp);
        }
        printf("%lld\n",ans);
    }
}
