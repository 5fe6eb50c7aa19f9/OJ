#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int data[10000][4];
int ptr[10000];
int flag[10000];
int remain1,remain2,remain3;
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
void comp(int a,int b){
    for(int i=0;i<3;i++){
        if(data[a][i]==data[b][i]||(data[a][i]<data[b][i]!=data[a][0]<data[b][0]))return;
    }
    if(data[a][0]<data[b][0]){
        flag[a]=0;
    }else{
        flag[b]=0;
    }
}
bool sd(int a,int b){//for Standard Deviation
    if(data[a][3]!=data[b][3])return data[a][3]<data[b][3];
    return a<b;
}
int main(){
    int t,n,i,j,k,tmp,lcm;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d %d %d %c",data[i],data[i]+1,data[i]+2,data[i]+3);
            data[i][3]%=256;//avoid bug
            flag[i]=1;
        }
        remain1=0;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(data[i][3]!=data[j][3])comp(i,j);
            }
            if(flag[i]){
                tmp=data[i][0]+data[i][1]+data[i][2];
                data[i][3]=0;
                for(j=0;j<3;j++){
                    data[i][3]+=(data[i][j]*3-tmp)*(data[i][j]*3-tmp);
                }
                ptr[remain1++]=i;
            }
        }
        sort(ptr,ptr+remain1,sd);
        remain2=remain1-(remain1+1)/2;
        for(i=remain2,tmp=0;i<remain1;i++){
            tmp+=data[ptr[i]][0]+data[ptr[i]][1]+data[ptr[i]][2];
        }
        for(i=remain2;i<remain1;i++){
            if((data[ptr[i]][0]+data[ptr[i]][1]+data[ptr[i]][2])*((remain1+1)/2)>=tmp){
                ptr[remain2++]=ptr[i];
            }
        }
        sort(ptr,ptr+remain2);
        lcm=1;
        for(i=0;i<remain2;i++){
            flag[i]=ptr[i]+1;//flag[i]=count of ptr[i]
        }
        for(i=0;i<remain2;i++){
            for(j=i+1;j<remain2;j++){
                flag[j]/=gcd(flag[i],flag[j]);
            }
            lcm=lcm*flag[i]%remain2;
        }
        for(i=0;i<remain2;i++){
            flag[i]=i+1<remain2?i+1:0;//flag[i]=next index of i
        }
        k=lcm+remain2;
        remain3=remain2;
        j=k%remain3?k%remain3:remain3;
        for(i=0,tmp=remain2-1;flag[i]!=flag[tmp];i=flag[i],j--){//flag[tmp]=i
            if(j==1){
                remain3--;
                j=k%remain3?k%remain3:remain3;
                flag[tmp]=flag[i];
                j++;
            }else{
                tmp=flag[tmp];
            }
        }
        printf("%d\n",ptr[i]+1);
    }
}
