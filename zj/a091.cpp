#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct heap{
    int num;
    int v[1000001];
    void push(int k){
        v[++num]=k;
        int i=num;
        if((32-__builtin_clz(num))&1){
            if(i>>1>0&&v[i]<v[i>>1]){
                swap(v[i],v[i>>1]);
                minpush(i>>1);
            }else{
                maxpush(i);
            }
        }else{
            if(i>>1>0&&v[i]>v[i>>1]){
                swap(v[i],v[i>>1]);
                maxpush(i>>1);
            }else{
                minpush(i);
            }
        }
    }
    void maxpush(int i){
        while(i>>2>0&&v[i]>v[i>>2]){
            swap(v[i],v[i>>2]);
            i>>=2;
        }
    }
    void minpush(int i){
        while(i>>2>0&&v[i]<v[i>>2]){
            swap(v[i],v[i>>2]);
            i>>=2;
        }
    }
    void pop(int i){
        if(i==1){
            maxpop(i);
        }else{
            minpop(i);
        }
    }
    void maxpop(int i){
        v[i]=v[num--];
        int j,k;
        while(i<<2<=num){
            j=i<<1;
            if(v[j]<v[j+1])j++;
            if(v[i]<v[j])swap(v[i],v[j]);
            j=i<<2;
            for(k=1;k<4&&(i<<2)+k<=num;k++){
                if(v[j]<v[(i<<2)+k]){
                    j=(i<<2)+k;
                }
            }
            if(v[i]<v[j]){
                swap(v[i],v[j]);
                i=j;
            }else{
                break;
            }
        }
        j=i<<1;
        if(j>num)return;
        if(j+1<=num&&v[j]<v[j+1])j++;
        if(v[i]<v[j])swap(v[i],v[j]);
    }
    void minpop(int i){
        v[i]=v[num--];
        int j,k;
        while(i<<2<=num){
            j=i<<1;
            if(v[j]>v[j+1])j++;
            if(v[i]>v[j])swap(v[i],v[j]);
            j=i<<2;
            for(k=1;k<4&&(i<<2)+k<=num;k++){
                if(v[j]>v[(i<<2)+k]){
                    j=(i<<2)+k;
                }
            }
            if(v[i]>v[j]){
                swap(v[i],v[j]);
                i=j;
            }else{
                break;
            }
        }
        j=i<<1;
        if(j>num)return;
        if(j+1<=num&&v[j]>v[j+1])j++;
        if(v[i]>v[j])swap(v[i],v[j]);
    }
    int maxv(){
        return 1;
    }
    int minv(){
        if(num==1)return 1;
        if(num==2)return 2;
        if(v[2]<v[3])return 2;
        return 3;
    }
};
heap h;
int main(){
    int i,j,k;
    h.num=0;
    while(scanf("%d",&k)==1){
        if(k==1){
            scanf("%d",&k);
            h.push(k);
        }else if(k==2){
            j=h.maxv();
            printf("%d\n",h.v[j]);
            h.pop(j);
        }else{
            j=h.minv();
            printf("%d\n",h.v[j]);
            h.pop(j);
        }
    }
}
