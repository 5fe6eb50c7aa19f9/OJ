#include <cstdio>
void change(int& a,int& b){
    int tmp=a;
    a=b;
    b=tmp;
}
int matrix[10][10];
int tmpM[10][10];
int main(){
    int i,j,R,C,M,tmp,V,H,W;//Vertical;Horizon;clock Wise
    while(scanf("%d %d %d",&R,&C,&M)==3){
        for(i=0;i<R;i++){
            for(j=0;j<C;j++){
                scanf("%d",&matrix[i][j]);
            }
        }
        V=0,H=0,W=0;
        for(i=0;i<M;i++){
            scanf("%d",&tmp);
            if(tmp==0){
                W++;
                W%=4;
            }else{
                if(W&1){
                    H++;
                    H&=1;
                }else{
                    V++;
                    V&=1;
                }
            }
        }
        //the motion is belong to A now, not B
        W=(4-W)%4;
        if(W&1)change(V,H);
        if(H){
            for(i=0;i<R;i++){
                for(j=0;j<C/2;j++){
                    change(matrix[i][j],matrix[i][C-j-1]);
                }
            }
        }
        if(V){
            for(i=0;i<C;i++){
                for(j=0;j<R/2;j++){
                    change(matrix[j][i],matrix[R-j-1][i]);
                }
            }
        }
        while(W-->0){
            for(i=0;i<C;i++){
                for(j=R-1;j>=0;j--){
                    tmpM[i][R-j-1]=matrix[j][i];
                }
            }
            change(R,C);
            for(i=0;i<R;i++){
                for(j=0;j<C;j++)matrix[i][j]=tmpM[i][j];
            }
        }
        printf("%d %d\n",R,C);
        for(i=0;i<R;i++){
            for(j=0;j<C;j++){
                printf("%d",matrix[i][j]);
                if(j!=C-1)printf(" ");
            }
            printf("\n");
        }
    }
}
