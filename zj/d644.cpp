#include <cstdio>
#include <algorithm>
using namespace std;

struct matrix{
    long long v[5][5];
};
matrix root,identity,tmp1,tmp2;
matrix mul(matrix& a,matrix& b){
    matrix ret;
    int i,j,k;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            ret.v[i][j]=0;
            for(k=0;k<5;k++){
                ret.v[i][j]+=a.v[i][k]*b.v[k][j];
            }
            ret.v[i][j]%=100019;
        }
    }
    return ret;
}
int main(){
    int n,i,j,k;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++)root.v[i][j]=identity.v[i][j]=0;
    }
    for(i=0;i<5;i++)identity.v[i][i]=1;
    root.v[0][1]=1;root.v[0][2]=2;root.v[0][3]=1;root.v[0][4]=-1;
    root.v[1][0]=root.v[2][1]=root.v[3][2]=root.v[4][4]=1;
    while(scanf("%d",&n)==1){
        if(n<=2){
            printf("1\n");
        }else if(n<=4){
            printf("2\n");
        }else{
            n-=4;
            tmp1=root;
            tmp2=identity;
            while(n){
                if(n&1){
                    tmp2=mul(tmp1,tmp2);
                }
                tmp1=mul(tmp1,tmp1);
                n>>=1;
            }
            printf("%d\n",(tmp2.v[0][0]*2+tmp2.v[0][1]*2+tmp2.v[0][2]+tmp2.v[0][3]+tmp2.v[0][4])%100019);
        }
    }
}
