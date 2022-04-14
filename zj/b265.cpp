#include <cstdio>
#include <algorithm>

int data[10000][5];
int* ptr[10000];
bool cmp(int* a,int* b){//for merge sort
    for(int i=0;i<5;i++){
        if(a[i]<b[i]){
            return 1;
        }else if(a[i]>b[i]){
            return 0;
        }
    }
    return 0;
}
void Merge(int l,int r){
    if(l>=r-1)return;
    int mid=(l+r)>>1;
    Merge(l,mid);
    Merge(mid,r);
    int* tmp[r-l];
    for(int i=l,j=mid,k=0;k<r-l;k++){
        if(i==mid){
            tmp[k]=ptr[j++];
        }else if(j==r){
            tmp[k]=ptr[i++];
        }else if(cmp(ptr[i],ptr[j])){
            tmp[k]=ptr[i++];
        }else{
            tmp[k]=ptr[j++];
        }
    }
    for(int i=0,j=l;i<r-l;i++,j++){
        ptr[j]=tmp[i];
    }
}
bool exam(int* a,int* b){//exam if they are same,for binary search
    for(int i=0;i<5;i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}
int BS(int l,int r,int target){
    if(l>=r-1){
        return l;
    }
    int mid=(r+l)>>1;
    if(exam(ptr[mid],ptr[target])){
        return BS(mid,r,target);
    }
    return BS(l,mid,target);
}
int main(){
    int n,i,j,num,sum,tmp;
    bool flag;
    while(scanf("%d",&n)&&n){
        for(i=0;i<n;i++){
            ptr[i]=data[i];
            for(j=0;j<5;j++){
                scanf("%d",&data[i][j]);
            }
            std::sort(data[i],data[i]+5);
        }
        Merge(0,n);
        num=-1,sum=-1;
        for(i=0;i<n;i++){
            int identical=BS(i,n,i);
            tmp=identical-i+1;
            i=identical;
            if(num==tmp){
                sum+=tmp;
            }else if(num<tmp){
                num=tmp;
                sum=tmp;
            }
        }
        printf("%d\n",sum);
    }
}
