#include <cstdio>
#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> s;
int data[20];
int N;
void brute(int *data,int N,int sum){
    if(N==0){
        s.insert(sum);
        return;
    }
    brute(data+1,N-1,sum+*data);
    brute(data+1,N-1,sum);
}
int main(){
    int i,v;
    while(scanf("%d",&N)==1){
        s.clear();
        for(i=0;i<N;i++){
            scanf("%d",data+i);
        }
        brute(data,N,0);
        printf("%d\n",s.size()-1);
    }
}

