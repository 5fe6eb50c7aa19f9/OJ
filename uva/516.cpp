#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;

struct A{
    int v,e;
};
int seive[400>>5];
int prime[40];
list<A> ans;
int main(){
    int i,j,k=0;
    char tmp;
    prime[k++]=2;
    for(i=3;i<400;i+=2){
        if((seive[i>>5]>>(i&31))%2==0){
            prime[k++]=i;
            for(j=i*i;j<400;j+=i){
                seive[j>>5]|=1<<(j&31);
            }
        }
    }
    while(scanf("%d%*c",&i)==1&&i){
        k=1;
        scanf("%d%c",&j,&tmp);
        while(j--)k*=i;
        while(tmp!='\n'){
            scanf("%d%*c%d%c",&i,&j,&tmp);
            while(j--)k*=i;
        }
        k--;
        for(i=0;prime[i]*prime[i]<=k;i++){
            if(k%prime[i]==0){
                j=0;
                do{
                    k/=prime[i];
                    j++;
                }while(k%prime[i]==0);
                ans.push_front(A{prime[i],j});
            }
        }
        if(k!=1){
            ans.push_front(A{k,1});
        }
        printf("%d %d",ans.front().v,ans.front().e);
        ans.pop_front();
        while(!ans.empty()){
            printf(" %d %d",ans.front().v,ans.front().e);
            ans.pop_front();
        }
        printf("\n");
    }
}
