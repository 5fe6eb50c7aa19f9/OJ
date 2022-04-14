#include <cstdio>
#include <algorithm>
using namespace std;

int flag[20000];
int main(){
    int t=1,z,i,m,l,r,c;
    while(scanf("%d %d %d %d",&z,&i,&m,&l)==4&&(z||i||m||l)){
        l%=m;
        for(r=0;r<m*2;r++)flag[r]=-1;
        r=0;
        while(flag[l+m]==-1){
            flag[l+m]=r++;
            l=(z*l+i)%m;
        }
        printf("Case %d: %d\n",t++,r-flag[l+m]);
    }
}
