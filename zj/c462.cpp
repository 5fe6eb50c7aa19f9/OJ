#include <cstdio>
#include <algorithm>
using namespace std;

char data[100001];
int one[100000],two[100000];
int res[100000];
int n;
int sol(int i){
    if(!data[i])return 0;
    if(res[i]!=-1)return res[i];
    if(data[i]==1){
        if(one[i]>n){
            res[i]=1;
        }else if(one[i]==n){
            res[i]=sol(i+n)+1;
        }else{
            res[i]=0;
        }
    }else{
        if(two[i]>n){
            res[i]=1;
        }else if(two[i]==n){
            res[i]=sol(i+n)+1;
        }else{
            res[i]=0;
        }
    }
    return res[i];
}
int main(){
    int i,j,k,ans;
    scanf("%d",&n);
    scanf("%s",data);
    for(i=0;data[i];i++){
        if(data[i]>='a'&&data[i]<='z'){
            data[i]=1;
        }else{
            data[i]=2;
        }
        res[i]=-1;
    }
    for(i=i-1,j=k=0;i>=0;i--){
        if(data[i]==1){
            j++;
            k=0;
        }else{
            k++;
            j=0;
        }
        one[i]=j;
        two[i]=k;
    }
    for(i=ans=0;data[i];i++){
        if(res[i]==-1)sol(i);
        ans=max(ans,res[i]);
    }
    printf("%d\n",ans*n);
}
