#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char tmp[600000];
char data[1200000];
int k[1200000];
int main(){
    int t,i,j,ans;
    for(i=0;i<1200000;i+=2)data[i]='.';
    scanf("%d%*c",&t);
    while(t--){
        scanf("%[^\n]%*c",tmp);
        for(i=0;;i++){
            data[i*2+1]=tmp[i];
            if(!tmp[i])break;
        }
        ans=1;
        k[0]=1;
        for(i=1,j=0;data[i];i++){
            if(j+k[j]-1<i){
                k[i]=0;
                while(i-k[i]>=0&&data[i+k[i]]&&data[i-k[i]]==data[i+k[i]])k[i]++;
            }else{
                if(i+k[j*2-i]<j+k[j]){
                    k[i]=k[j*2-i];
                }else if(i+k[j*2-i]==j+k[j]){
                    k[i]=k[j*2-i];
                    while(i-k[i]>=0&&data[i+k[i]]&&data[i-k[i]]==data[i+k[i]])k[i]++;
                }else{
                    k[i]=j+k[j]-i;
                }
            }
            ans=max(ans,(k[i]*2-1)/2);
            if(j+k[j]<i+k[i])j=i;
        }
        printf("%d\n",ans);
    }
}
