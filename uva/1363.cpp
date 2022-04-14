#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    unsigned long long n,k,flag,r,ans;
    while(scanf("%llu %llu",&n,&k)==2){
        ans=0;
        if(n>=k){//k%n=k if n>k
            ans+=k*(n-k);
            n=k-1;
        }
        while(n>1){
            r=k/n;//ratio
            flag=k/(r+1)+1;//the minimum number that is smaller than k when multiply r and bigger than k when multiply r+1 (maximum is n)
            ans+=(k%n+k%flag)*(n-flag+1)/2;//the neighbor numbers have fixed distance if they have above property
            n=flag-1;
        }
        printf("%llu\n",ans);
    }
}
