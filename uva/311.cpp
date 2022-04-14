#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int data[6];
int main(){
    int t=0,i,j,two,one,ans;
    while(1){
        for(i=j=0;i<6;i++){
            scanf("%d",data+i);
            j+=data[i];
        }
        if(j==0)break;
        //if(t++)printf("\n");
        ans=data[5]+data[4]+data[3];
        one=data[4]*11;
        two=data[3]*5;
        if(data[2]%4==0){
            ans+=data[2]/4;
        }else{
            ans+=data[2]/4+1;
            if(data[2]%4==1){
                one+=7;
                two+=5;
            }else if(data[2]%4==2){
                one+=6;
                two+=3;
            }else{
                one+=5;
                two++;
            }
        }
        two-=data[1];
        if(two<0){
            two*=-1;
            if(two%9==0){
                ans+=two/9;
            }else{
                ans+=two/9+1;
                one+=(9-two%9)*4;
            }
        }else{
            one+=two*4;
        }
        one-=data[0];
        if(one<0){
            one*=-1;
            if(one%36==0){
                ans+=one/36;
            }else{
                ans+=one/36+1;
            }
        }
        printf("%d\n",ans);
    }
}
