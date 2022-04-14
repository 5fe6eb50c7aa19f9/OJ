#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
string bottle="GBC";
int data[3][3];
int sum[3];
int ans;
string res;
void sol(int i){
    if(i==3){
        int tmp=0;
        for(i=0;i<3;i++){
            if(bottle[i]=='B'){
                tmp+=sum[0]-data[i][0];
            }else if(bottle[i]=='G'){
                tmp+=sum[1]-data[i][1];
            }else{
                tmp+=sum[2]-data[i][2];
            }
        }
        if(ans>tmp){
            ans=tmp;
            res=bottle;
        }else if(ans==tmp&&bottle<res){
            res=bottle;
        }
        return;
    }
    for(int j=i;j<3;j++){
        swap(bottle[i],bottle[j]);
        sol(i+1);
        swap(bottle[i],bottle[j]);
    }
}
int main(){
    int i,j,k;
    while(scanf("%d",data[0])==1){
        for(i=0;i<3;i++){
            j=i==0?1:0;
            for(;j<3;j++){
                scanf("%d",data[i]+j);
            }
        }
        for(i=0;i<3;i++){
            sum[i]=0;
        }
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                sum[i]+=data[j][i];
            }
        }
        ans=0x7fffffff;
        sol(0);
        cout<<res<<" "<<ans<<endl;
    }
}
