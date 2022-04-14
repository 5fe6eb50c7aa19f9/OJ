#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int data[45];
char tmp[3];
int main(){
    int t,n,i;
    bool flag;
    scanf("%d",&t);
    while(t--){
        scanf("%d\n",&n);
        if(n>45){
            scanf("%*[^\n]",tmp);
            printf("YES\n");
        }else{
            for(i=0;i<n;i++)scanf("%d",data+i);
            sort(data,data+n);
            flag=0;
            for(i=2;i<n;i++){
                if(data[i]<data[i-1]+data[i-2]){
                    flag=1;
                    break;
                }
            }
            if(flag){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
}
