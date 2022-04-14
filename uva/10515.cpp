#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;
string m,n;
int main(){
    int i,j,M,N,ans;
    while(cin>>m>>n&&!(m=="0"&&n=="0")){
        M=m[m.size()-1]-'0';
        N=n[n.size()-1]-'0';
        if(n.size()>=2)N+=(n[n.size()-2]-'0')*10;
        if(n=="0"){
            printf("1\n");
            continue;
        }
        if(M==0||M==1||M==5||M==6){
            ans=M;
        }else if(M==2){
            switch(N%4){
                case 0:ans=6;break;
                case 1:ans=2;break;
                case 2:ans=4;break;
                case 3:ans=8;break;
            }
        }else if(M==3){
            switch(N%4){
                case 0:ans=1;break;
                case 1:ans=3;break;
                case 2:ans=9;break;
                case 3:ans=7;break;
            }
        }else if(M==4){
            switch(N%2){
                case 0:ans=6;break;
                case 1:ans=4;break;
            }
        }else if(M==7){
            switch(N%4){
                case 0:ans=1;break;
                case 1:ans=7;break;
                case 2:ans=9;break;
                case 3:ans=3;break;
            }
        }else if(M==8){
            switch(N%4){
                case 0:ans=6;break;
                case 1:ans=8;break;
                case 2:ans=4;break;
                case 3:ans=2;break;
            }
        }else if(M==9){
            switch(N%2){
                case 0:ans=1;break;
                case 1:ans=9;break;
            }
        }
        printf("%d\n",ans);
    }
}
