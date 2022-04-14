#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int sep;
struct Prob{
    int l,r,k,index;
    bool operator<(Prob& b){
        if(l/sep!=b.l/sep)return l<b.l;
        return r<b.r;
    }
};
int data[100000];
int* ptr[100000];
int Hash[100000];
Prob prob[5000];
int ans[5000];
int cnt1[400];
int cnt2[400][400];
bool cmp(int* a,int* b){
    return *a<*b;
}
inline int add(int i){
    cnt1[data[i]/sep]++;
    cnt2[data[i]/sep][data[i]%sep]++;
}
inline int sub(int i){
    cnt1[data[i]/sep]--;
    cnt2[data[i]/sep][data[i]%sep]--;
}
int main(){
    int n,m,i,j,k,l,r;
    while(scanf("%d %d",&n,&m)==2){
        for(i=0;i<400;i++){
            cnt1[i]=0;
            for(j=0;j<400;j++){
                cnt2[i][j]=0;
            }
        }
        for(i=0;i<n;i++){
            scanf("%d",data+i);
            ptr[i]=data+i;
        }
        sort(ptr,ptr+n,cmp);
        for(i=0;i<n;i++){
            Hash[i]=*ptr[i];
            *ptr[i]=i;
        }
        for(i=0;i<m;i++){
            scanf("%d %d %d",&prob[i].l,&prob[i].r,&prob[i].k);
            prob[i].l--;
            prob[i].r--;
            prob[i].index=i;
        }
        sep=sqrt(n);
        sort(prob,prob+m);
        l=r=0;
        cnt1[data[0]/sep]++;
        cnt2[data[0]/sep][data[0]%sep]++;
        for(i=0;i<m;i++){
            while(prob[i].l<l)add(--l);
            while(prob[i].l>l)sub(l++);
            while(prob[i].r<r)sub(r--);
            while(prob[i].r>r)add(++r);
            for(j=0;;j++){
                if(prob[i].k>cnt1[j]){
                    prob[i].k-=cnt1[j];
                }else{
                    for(k=0;;k++){
                        prob[i].k-=cnt2[j][k];
                        if(prob[i].k<=0){
                            ans[prob[i].index]=Hash[j*sep+k];
                            break;
                        }
                    }
                    break;
                }
            }
        }
        for(i=0;i<m;i++){
            printf("%d\n",ans[i]);
        }
    }
}
