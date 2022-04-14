#include <cstdio>
#include <algorithm>
using namespace std;

int flag[100];
int n;
int sol(int i,int j){
    while(1){
        if(flag[i])j--;
        if(!j)break;
        i=(i+1)%n;
    }
    return i;
}
int main(){
    int m,i,j,k,tmp;
    while(scanf("%d %d",&n,&m)==2&&n+m){
        for(i=0;i<n;i++)flag[i]=i+1;
        for(i=0,tmp=n;tmp>1;tmp--){
            j=sol(i,m);
            flag[j]=0;
            k=sol((j+1)%n,m);
            swap(flag[j],flag[k]);
            i=(j+1)%n;
        }
        for(i=0;i<n;i++){
            if(flag[i]){
                printf("%d\n",flag[i]==1?1:1+n-flag[i]+1);
                break;
            }
        }
    }
}
