#include <iostream>
using namespace std;

int n;
int data[5];
int data2[5];
bool calcu(int sum,int flag){
    if(sum<=0){
        if(sum==0){
            cout<<'(';
            for(int i=0;i<n;i++)cout<<data2[i]<<(i==n-1?')':',');
            cout<<endl;
        }
        return true;
    }else if(flag==n)return false;

    for(;;data2[flag]++){
        if(calcu(sum-data[flag]*data2[flag],flag+1))break;
    }
    data2[flag]=0;
    return false;
}
int main(){
    while(cin>>n){
        int sum;
        for(int i=0;i<n;i++){
            cin>>data[i];
            data2[i]=0;
        }
        cin>>sum;
        calcu(sum,0);
    }
}
