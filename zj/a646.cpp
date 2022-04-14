#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int c,ans,s,m,i,j,x,y;
    string p;
    while(cin>>c>>p){
        if(p=="0"||p=="0.0"||p=="0.00"||p=="0.000"){
            printf("%d\n",c);
            continue;
        }
        for(i=2,s=0;i<5;i++){
            if(i<p.size())s=s*10+p[i]-'0';
            else s*=10;
        }
        m=1000;
        while(s%2==0&&m%2==0){
            s/=2;
            m/=2;
        }
        while(s%5==0&&m%5==0){
            s/=5;
            m/=5;
        }
        ans=c;
        while(c>=m){
            ans+=(c/m)*s;
            c=c%m+(c/m)*s;
        }
        while(c>0){
            for(i=1,x=0,y=0;i<=c;i++){// c/p=x/y
                j=(i*s)/m;
                if(y==0||j*y>x*i){
                    x=j;
                    y=i;
                }
            }
            ans+=x;
            c=c-y+x;
        }
        printf("%d\n",ans);
    }
}
