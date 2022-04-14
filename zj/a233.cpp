#include <iostream>
#include <cstdio>
using namespace std;

int* Mer(int*,int);
int main()
{
    int a;
    while(cin>>a){
        int data[a];
        for(int i=0;i<a;i++)scanf("%d",&data[i]);
        Mer(data,a);
        for(int i=0;i<a;i++)printf("%d ",data[i]);
        cout<<endl;
    }
}
int* Mer(int* test,int n){
    if(n==1)return test;

    int tmp=n/2;
    int* left=Mer(test,tmp);
    int* right=Mer(test+tmp,n-tmp);
    int Left[tmp]={0};
    int Right[n-tmp]={0};
    for(int i=0;i<tmp;i++){
        Left[i]=*(left+i);
    }
    for(int i=0;i<n-tmp;i++){
        Right[i]=*(right+i);
    }
    for(int i=0,j=0,k=0;i<n;i++){
        if((Left[j]>=Right[k]&&k<n-tmp)||j==tmp){
            test[i]=Right[k];
            k++;
        }else {
            test[i]=Left[j];
            j++;
        }
    }
    return test;
}
