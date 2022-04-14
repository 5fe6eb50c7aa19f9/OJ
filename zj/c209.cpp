#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    bool flag;
    int n,i,j,k,ans;
    long long data[100];
    long long a,b,c,tmp,one=1;
    while(scanf("%d",&n)==1){
        flag=1;
        a=0xffffffffffffffff;
        b=0xffffffffffffffff;
        for(i=0;i<n;i++){
            scanf("%lld",&data[i]);
            a&=data[i];
            b&=~data[i];
            if(i>0&&data[i-1]>=data[i])flag=0;
        }
        c=a|b;
        for(i=59;i>=0&&!flag;i--){
            tmp=one<<i;
            if((c&tmp)==0){
                for(j=0;j<n-1;j++){
                    if(data[j]>data[j+1]&&(data[j]&tmp)!=0&&(data[j+1]&tmp)==0){
                        for(k=0;k<n;k++){
                            data[k]^=tmp;
                        }
                        break;
                    }
                }
                for(j=0;j<n-1;j++){
                    if(data[j]>=data[j+1]){
                        break;
                    }
                    if(j==n-2)flag=1;
                }
            }
        }
        if(flag){
            for(ans=0,i=59;i>=0;i--){
                tmp=one<<i;
                if(c&tmp){
                    ans++;
                }else{
                    for(j=0;j<n-1;j++){
                        if((data[j]^tmp)>=(data[j+1]^tmp)){
                            break;
                        }
                        if(j==n-2)ans++;
                    }
                }
            }
            printf("%lld\n",one<<ans);
        }else{
            printf("0\n");
        }
    }
}
