#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    long long data[500]={0};
    long long ans[500]={0};
    long long flag;
    int N,m,k;
    scanf("%d",&N);
    while(0<N--){
        scanf("%d %d",&m,&k);
        for(int i=0;i<m;i++){
            scanf("%d",&data[i]);
        }
        for(long long l=data[m-1]-1,h=5000000001,mid=(l+h)>>1;mid!=l&&mid!=h;mid=(l+h)>>1){
            for(long long i=1,j=0,tmp;;i++){
                if(i>k){
                    l=mid;
                    break;
                }
                tmp=0;
                while(j!=m&&tmp+data[j]<=mid){
                    tmp+=data[j++];
                }
                if(j==m){
                    flag=mid;
                    h=mid;
                    break;
                }
            }
        }
        for(long long i=k-1,j=m-1,tmp;i>0;i--){
            tmp=0;
            while(j+1>i&&tmp+data[j]<=flag){
                tmp+=data[j--];
            }
            ans[i-1]=j;
        }
        for(int i=0,j=0;i<m;i++){
            printf("%d",data[i]);
            if(i==m-1){
                printf("\n");
            }else if(i==ans[j]){
                j++;
                printf(" / ");
            }else{
                printf(" ");
            }
        }
    }
}
