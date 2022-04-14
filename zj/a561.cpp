#include <cstdio>
int data[(10000000>>5)+1];
int main(){
    int n,i;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&i);
        data[i>>5]|=1<<(i&31);
    }
    for(i=0,n=-1;i<10000000;i++){
        if((data[i>>5]>>(i&31))&1){
            n++;
            if(n%10==0)printf("%d ",i);
        }
    }
}
