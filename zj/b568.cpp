#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <bitset>
using namespace std;

bitset<700001> bs;
int main(){
    int n,i;
    while(scanf("%d",&n)==1){
        bs=1;
        while(n--){
            scanf("%d",&i);
            bs|=(bs<<i)|(bs>>(700000-i));
        }
        for(i=700000;;i--){
            if(bs[i]){
                printf("%d\n",i);
                break;
            }
        }
    }
}
