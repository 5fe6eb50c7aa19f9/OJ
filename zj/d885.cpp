#include <iostream>
#include <cstdio>
using namespace std;

int data[5000000][2];
int tmp[100000][2];
int DnC(int l,int r){
    if(l+1==r){
        return 1;
    }
    int m=(l+r)/2,i,j,k,lnum=DnC(l,m),rnum=DnC(m,r),num;
    for(i=0,j=l,k=m;j<l+lnum||k<m+rnum;){
        if(j==l+lnum){
            if(i==0||tmp[i-1][0]!=data[k][0]){
                tmp[i++][1]=0;
            }
            tmp[i-1][0]=data[k][0];
            tmp[i-1][1]+=data[k][1];
            k++;
        }else if(k==m+rnum){
            if(i==0||tmp[i-1][0]!=data[j][0]){
                tmp[i++][1]=0;
            }
            tmp[i-1][0]=data[j][0];
            tmp[i-1][1]+=data[j][1];
            j++;
        }else if(data[j][0]<data[k][0]){
            if(i==0||tmp[i-1][0]!=data[j][0]){
                tmp[i++][1]=0;
            }
            tmp[i-1][0]=data[j][0];
            tmp[i-1][1]+=data[j][1];
            j++;
        }else{
            if(i==0||tmp[i-1][0]!=data[k][0]){
                tmp[i++][1]=0;
            }
            tmp[i-1][0]=data[k][0];
            tmp[i-1][1]+=data[k][1];
            k++;
        }
    }
    num=i;
    for(i=0,j=l;i<num;i++,j++){
        data[j][0]=tmp[i][0];
        data[j][1]=tmp[i][1];
    }
    return num;
}
int main(){
    int i,n,num;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",data[i]);
        data[i][1]=1;
    }
    num=DnC(0,n);
    for(i=0;i<num;i++){
        printf("%d %d\n",data[i][0],data[i][1]);
    }
}
