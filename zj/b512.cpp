#include <iostream>
#include <cstdio>
using namespace std;

long long data[100000000][2];
int main(){
    int n=0,sum=0;
    char Skip;
    while(scanf("%d %c %d",&data[n][0],&Skip,&data[n][1])&&!(data[n][0]==0&&data[n][1]==0)){
        n++;
    }
    int tmp1,tmp2;
    while(scanf("%d %c %d",&tmp1,&Skip,&tmp2)&&!(tmp1==0&&tmp2==0)){
        for(int i=0;i<n;i++){
            if(data[i][0]==tmp1)sum+=data[i][1]*tmp2;
        }
    }
    cout<<sum<<endl;
}
