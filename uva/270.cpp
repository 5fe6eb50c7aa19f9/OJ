#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int x[700],y[700];
string buf;
int main(){
    int t,n,i,j,k,tmp,ans;
    scanf("%d%*c",&t);
    getline(cin,buf);
    while(t--){
        n=0;
        while(getline(cin,buf)){
            if(buf=="")break;
            x[n]=y[n]=i=j=0;
            if(buf[i]=='-'){
                j=1;
                i++;
            }
            while(buf[i]>='0'&&buf[i]<='9'){
                x[n]=x[n]*10+buf[i]-'0';
                i++;
            }
            if(j)x[n]*=-1;
            i++;
            j=0;
            if(buf[i]=='-'){
                j=1;
                i++;
            }
            while(i<buf.size()){
                y[n]=y[n]*10+buf[i]-'0';
                i++;
            }
            if(j)y[n]*=-1;
            n++;
        }
        ans=n>0;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                for(k=j+1,tmp=2;k<n;k++){
                    if((y[j]-y[i])*(x[k]-x[i])==(y[k]-y[i])*(x[j]-x[i]))tmp++;
                }
                ans=max(ans,tmp);
            }
        }
        printf("%d\n",ans);
        if(t)printf("\n");
    }
}
