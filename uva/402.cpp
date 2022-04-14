#include <cstdio>
#include <algorithm>
using namespace std;

int flag[20000];
int main(){
    int t=1,n,x,i,j,k,l;
    while(scanf("%d %d",&n,&x)==2){
        for(i=1;i<=n;i++)flag[i]=i;
        for(i=0;i<20;i++){
            scanf("%d",&k);
            j=n;
            l=k;
            while(j>x&&l<=n){
                flag[l]=0;
                j--;
                l+=k;
            }
            n=j;
            j=k;
            for(;j<=n;k++){
                if(flag[k])flag[j++]=flag[k];
            }
        }
        printf("Selection #%d\n",t++);
        printf("%d",flag[1]);
        for(i=2;i<=n;i++){
            printf(" %d",flag[i]);
        }
        printf("\n\n");
    }
}
