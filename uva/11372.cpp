#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define lll long long
#define etc1 [i][x[0]][x[1]][x[2]][x[3]][x[4]]
#define etc2 [i-1][x[0]-dx[0]][x[1]-dx[1]][x[2]-dx[2]][x[3]-dx[3]][x[4]-dx[4]]
struct node{
    lll v;
    char str[100];
    bool operator<(node& o){
        return v<o.v;
    }
};
node data[200];
int dp[7][3][3][5][4][4];
lll pa[7][3][3][5][4][4];//
int x[5],dx[5];
int ret;
lll res,tmp,v;//
int main(){
    int N,n,i,j;
    char* str;
    while(scanf("%d%*c",&N)==1&&N){
        for(i=0;i<7;i++){
            for(x[0]=0;x[0]<3;x[0]++){
                for(x[1]=0;x[1]<3;x[1]++){
                    for(x[2]=0;x[2]<5;x[2]++){
                        for(x[3]=0;x[3]<4;x[3]++){
                            for(x[4]=0;x[4]<4;x[4]++){
                                dp etc1=-1;
                            }
                        }
                    }
                }
            }
        }
        dp [0][0][0][0][0][0]=0;
        for(i=0;i<N;i++){
            scanf("%lld %*s%*c",&data[i].v);
            fgets(data[i].str+30,50,stdin);
        }
        sort(data,data+N);
        for(n=1;n<=N;n++){
            v=data[n-1].v;
            str=data[n-1].str;
            for(i=0;i<5;i++)dx[i]=0;
            switch(str[30]){
                case 'E':dx[0]=1;break;
                case 'H':dx[1]=1;break;
            }
            switch(str[32]){
                case 'D':dx[2]=1;break;
                case 'M':dx[3]=1;break;
                case 'G':dx[4]=1;break;
            }
            for(i=min(6,n);i>0;i--){
                for(x[0]=2;x[0]>=dx[0];x[0]--){
                    for(x[1]=2;x[1]>=dx[1];x[1]--){
                        for(x[2]=4;x[2]>=dx[2];x[2]--){
                            for(x[3]=i-x[2];x[3]>=dx[3];x[3]--){
                                for(x[4]=i-x[2]-x[3];x[4]>=dx[4];x[4]--){
                                    if(dp etc2<0)continue;
                                    if(dp etc1<dp etc2+str[34]-'0'){//1
                                        dp etc1=dp etc2+str[34]-'0';
                                        pa etc1=(pa etc2*1000)+v;
                                    }else if(dp etc1==dp etc2+str[34]-'0'){
                                        pa etc1=min(pa etc1,(pa etc2*1000)+v);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        ret=-1;
        for(i=6,x[0]=x[1]=2,x[2]=min(6,4);N>=6&&x[2]>=2;x[2]--){
            for(x[3]=min(6-x[2],3);x[3]>=1;x[3]--){
                for(x[4]=min(6-x[2]-x[3],3);x[4]>=1;x[4]--){
                    if(ret<dp etc1){
                        ret=dp etc1;
                        res=pa etc1;
                    }else if(ret==dp etc1){
                        res=min(res,pa etc1);
                    }
                }
            }
        }
        if(ret!=-1){
            for(i=0,tmp=0;i<6;i++){
                tmp=tmp*1000+(res%1000);
                res/=1000;
            }
            for(i=0;i<6;i++){
                if(i)printf(" ");
                printf("%03d",tmp%1000);
                tmp/=1000;
            }
        }else{
            printf("No solution.");
        }
        printf("\n");
    }
}
/*
7
001 one E D 5
002 two E D 5
003 thr M M 5
004 fou M G 5
005 fiv H X 1
006 six H X 2
007 sev H X 1
7
000 SIMPLIFYING_FRACTIONS____ M M 2
001 ARRANGING_A_CONTEST______ E X 1
002 TRAVEL_IN_DESERT_________ M G 5
003 LONGEST_PALINDROME_______ E D 4
004 HEADMASTER¡¦S_HEADACHE____ H D 4
005 ANDY¡¦S_FIRST_DICTIONARY__ E X 4
006 POWER_OF_MATRIX__________ H M 3
0

*/
