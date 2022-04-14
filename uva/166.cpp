#include <cstdio>
#include <iostream>
using namespace std;

int v[6]={5,10,20,50,100,200};
int num[6];
int go(int i,int sum){
    if(i==6){
        if(sum>0)return -1;
        int ans=0;
        sum*=-1;
        for(i=i-1;i>=0;i--){
            ans+=sum/v[i];
            sum%=v[i];
        }
        return ans;
    }
    int ans=0x7fffffff,tmp;
    for(int j=0;j<=num[i];j++){
        tmp=go(i+1,sum-v[i]*j);
        if(tmp!=-1)ans=min(ans,tmp+j);
    }
    if(ans!=0x7fffffff)return ans;
    return -1;
}
int main(){
    int i,j,sum;
    string tmp;
    while(1){
        for(i=j=0;i<6;i++){
            scanf("%d",num+i);
            j+=num[i];
        }
        if(j==0)break;
        cin>>tmp;
        sum=(tmp[0]-'0')*100;
        if(tmp.size()>=3)sum+=(tmp[2]-'0')*10;
        if(tmp.size()>=4)sum+=(tmp[3]-'0');
        printf("%3d\n",go(0,sum));
    }
}
