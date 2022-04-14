#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long acc[65537];
int num[65537];
void greedy(int flag,int L){
    if(flag==0||L==0)return;
    num[flag]+=L/flag;
    L%=flag;
    greedy(flag-1,L);
}
int main(){
    int L,i,l,r,m,flag;
    for(i=1;i<65537;i++){
        acc[i]+=acc[i-1]+i;
    }
    for(i=65536;i>0;i--){
        acc[i]+=acc[i-1];
    }
    while(scanf("%d",&L)==1){
        l=0,r=65537;
        while(l<r){
            m=(l+r)>>1;
            if(L>acc[m]){
                flag=m;
                l=m+1;
            }else if(L<acc[m]){
                r=m;
            }else{
                flag=m;
                break;
            }
        }
        for(i=1;i<=flag;i++)num[i]=1;
        greedy(flag,L-acc[flag]);
        for(i=1;i<=flag;i++){
            while(num[i]>0){
                printf("%d ",i);
                num[i]--;
            }
        }
        for(i=flag-1;i>0;i--){
            printf("%d ",i);
        }
        printf("\n");
    }
}
