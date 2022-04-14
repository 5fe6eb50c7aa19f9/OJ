#include <iostream>
#include <algorithm>
using namespace std;

long long data[100000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,sum,target,i,j,l,r,m,flag;
    while(cin>>n){
        for(i=0;i<n;i++){
            cin>>data[i];
        }
        sort(data,data+n);
        target=(n*(n-1))/2;
        if(target%2)target++;
        target>>=1;
        l=0,r=data[n-1]-data[0]+1;
        while(l<r){
            m=(l+r)>>1;
            for(i=0,sum=0;i<n-1;i++){
                sum+=(upper_bound(data+i+1,data+n,data[i]+m)-(data+i+1));
            }
            if(sum<target){
                l=m+1;
            }else{
                flag=m;
                r=m;
            }
        }
        cout<<flag<<endl;
    }
}
