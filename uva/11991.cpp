#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

vector<int> data[1000001];
int main()
{
    int n,m,k,v,flag;
    while(scanf("%d %d",&n,&m)==2){
        for(int i=0;i<n;i++){
            scanf("%d",&flag);
            data[flag].push_back(i+1);
        }
        for(int i=0;i<m;i++){
            scanf("%d %d",&k,&v);
            if(data[v].size()<k){
                printf("0\n");
            }else{
                printf("%d\n",data[v][k-1]);
            }
        }
        for(int i=0;i<1000001;i++)data[i].clear();
    }
}
