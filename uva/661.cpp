#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n,m,c,i,j,now,s=1;
    int flag;
    int data[20];
    while(scanf("%d %d %d",&n,&m,&c)&&!(n==0&&m==0&&c==0)){
        bool oc[m]={false};
        now=0;
        flag=0;
        for(i=0;i<n;i++){
            scanf("%d",&data[i]);
        }
        for(i=0;i<m;i++){
            scanf("%d",&j);
            j--;
            oc[j]=!oc[j];
            now=(oc[j]?now+data[j]:now-data[j]);
            if(now>flag)flag=now;
        }
        printf("Sequence %d\n",s);
        if(flag>c){
            printf("Fuse was blown.\n\n");
        }else{
            printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n",flag);
        }
        s++;
    }
}
