#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T>0){
        int N;
        scanf("%d",&N);
        int data[N][2]={0};
        for(int i=0,sum,tmp1;i<N;i++){
            sum=0;
            scanf("%d",&tmp1);
            data[i][0]=tmp1;
            for(int j=1,tmp2;j<N;j++){
                scanf("%d",&tmp2);
                sum+=tmp2-tmp1+N*(tmp2<tmp1);
                tmp1=tmp2;
            }
            data[i][1]=sum;
        }
        int last=0x7fffffff;
        for(int first=1,most;first<=N;first++){
            most=0;
            for(int i=0,num;i<N;i++){
                num=first+i;
                if(num>N)num-=N;
                if(data[i][1]+data[i][0]-num+N*(data[i][0]<num)>most)most=data[i][1]+data[i][0]-num+N*(data[i][0]<num);
            }
            if(last>most)last=most;
        }
        printf("%d\n",last);
        T--;
    }
}
