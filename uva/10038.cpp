#include <cstdio>
#include <iostream>
#include <unordered_set>
using namespace std;
#define abs(x) ((x)<0?(x)*-1:(x))
unordered_set<int> ans;
int main(){
    int n,i,a,b;
    while(scanf("%d",&n)==1){
        ans.clear();
        for(i=0;i<n;i++){
            scanf("%d",&b);
            if(i>0){
                if(abs(b-a)<n&&abs(b-a)>0){
                    ans.insert(abs(b-a));
                }
            }
            a=b;
        }
        if(ans.size()==n-1){
            printf("Jolly\n");
        }else{
            printf("Not jolly\n");
        }
    }
}
