#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
bool sol(int v){
    int tmp=pow(10,n/2);
    int a=v/tmp,b=v%tmp;
    if((a+b)*(a+b)==v)return 1;
    return 0;
}
int main(){
    int i,j,k,tmp;
    while(scanf("%d",&n)==1){
        tmp=pow(10,n);
        for(i=0;i*i<tmp;i++){
            if(sol(i*i)){
                switch(n){
                case 2:
                    printf("%02d\n",i*i);
                    break;
                case 4:
                    printf("%04d\n",i*i);
                    break;
                case 6:
                    printf("%06d\n",i*i);
                    break;
                case 8:
                    printf("%08d\n",i*i);
                    break;
                }
            }
        }
    }
}
