#include <cstdio>
#include <algorithm>
using namespace std;

char test[1000000];
double v[128];
int e[128];
bool exist[128];
double pow(int n){
    int s=n<0;
    if(n<0)n=-n;
    double ret=1.0,a=10.0;
    while(n){
        if(n&1)ret*=a;
        n>>=1;
        a*=a;
    }
    if(s)ret=1.0/ret;
    return ret;
}
int main(){
    int T,t,i,j,k;
    scanf("%d%*c",&T);
    for(t=1;t<=T;t++){
        scanf("%[^\n]%*c",test);
        exist['P']=exist['U']=exist['I']=0;
        for(i=0;test[i];i++){
            if(test[i]=='='){
                j=test[i-1];
                v[j]=0;
                exist[j]=1;
                i++;
                while(test[i]>='0'&&test[i]<='9'){
                    v[j]=v[j]*10+test[i]-'0';
                    i++;
                }
                k=0;
                if(test[i]=='.'){
                    i++;
                    while(test[i]>='0'&&test[i]<='9'){
                        v[j]=v[j]*10+test[i]-'0';
                        k--;
                        i++;
                    }
                }
                if(test[i]=='m'){
                    k-=3;
                }else if(test[i]=='k'){
                    k+=3;
                }else if(test[i]=='M'){
                    k+=6;
                }
                e[j]=k;
            }
        }
        if(!exist['P']){
            printf("Problem #%d\nP=%.2fW\n\n",t,v['I']*v['U']*pow(e['I']+e['U']));
        }else if(!exist['I']){
            printf("Problem #%d\nI=%.2fA\n\n",t,v['P']/v['U']*pow(e['P']-e['U']));
        }else if(!exist['U']){
            printf("Problem #%d\nU=%.2fV\n\n",t,v['P']/v['I']*pow(e['P']-e['I']));
        }
    }
}
