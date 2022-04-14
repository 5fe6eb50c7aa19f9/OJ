#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
    int n,two,ans,i,j;
    while(scanf("%d",&n)==1){
        two=0;
        ans=1;
        for(i=1;i<=n;i++){
            j=i;
            while(j%2==0){
                j/=2;
                two++;
            }
            while(j%5==0){
                j/=5;
                two--;
            }
            ans=ans*j%10;
        }
        if(two>0){
            two%=4;
            switch(two){
                case 0:
                    ans=ans*6%10;
                    break;
                case 1:
                    ans=ans*2%10;
                    break;
                case 2:
                    ans=ans*4%10;
                    break;
                case 3:
                    ans=ans*8%10;
                    break;
            }
        }
        printf("%5d -> %d\n",n,ans);
    }
}
