#include <cstdio>
#include <iostream>
using namespace std;
int fib[41];
int main(){
    int i,j,n,sum;
    fib[1]=1;
    for(n=2;n<=40;n++){
        fib[n]=fib[n-1]+fib[n-2];
    }
    scanf("%d",&n);
    while(n>0){
        scanf("%d",&sum);
        i=2;
        while(sum>=fib[i]){
            i++;
        }
        cout<<sum<<" = ";
        for(i=i-1;i>=2;i--){
            if(sum>=fib[i]){
                cout<<"1";
                sum-=fib[i];
            }else{
                cout<<'0';
            }
        }
        cout<<" (fib)\n";
        n--;
    }
}
