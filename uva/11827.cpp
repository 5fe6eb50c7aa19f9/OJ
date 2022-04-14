#include <cstdio>
#include <iostream>
using namespace std;
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    int data[100];
    string tmp;
    int n,i,j,m,ans,flag;
    scanf("%d",&n);
    getline(cin,tmp);
    while(n>0){
        n--;
        m=0;
        ans=0;
        data[0]=0;
        getline(cin,tmp);
        for(i=0;i<tmp.size();i++){
            if(tmp[i]==' '){
                if(i+1<tmp.size()&&tmp[i+1]>='0'&&tmp[i+1]<='9'){
                    data[++m]=0;
                }
                continue;
            }
            data[m]=data[m]*10+tmp[i]-'0';
        }
        for(i=0;i<=m-1;i++){
            for(j=i+1;j<=m;j++){
                flag=gcd(data[i],data[j]);
                if(flag>ans){
                    ans=flag;
                }
            }
        }
        printf("%d\n",ans);
    }
}
