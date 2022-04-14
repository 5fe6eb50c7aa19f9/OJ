#include <iostream>
#include <cstdio>
using namespace std;
int data[30];
bool knapsack[30001];
string tmp;
int main(){
    int n,i,j,k,sum;
    knapsack[0]=1;
    while(getline(cin,tmp,'\n')){
        for(n=i=j=sum=0;i<tmp.size();i++){
            if(tmp[i]==' '){
                sum+=j;
                data[n++]=j;
                j=0;
            }else{
                j=j*10+tmp[i]-'0';
            }
        }
        sum+=j;
        data[n++]=j;
        for(i=sum/2;i>0;i--)knapsack[i]=0;
        for(i=0;i<n;i++){
            for(j=sum/2;j-data[i]>=0;j--){
                if(knapsack[j-data[i]])knapsack[j]=1;
            }
        }
        for(i=sum/2;i>=0;i--){
            if(knapsack[i]){
                printf("%d\n",i*(sum-i));
                break;
            }
        }
    }
}
