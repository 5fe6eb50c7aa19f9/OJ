#include <iostream>
using namespace std;

int main(){
    int a;
    while(cin>>a){
        int data[a];
        for(int i=0;i<a;i++)cin>>data[i];
        int sum=0;
        for(int i=a;i>=1;i--){
            for(int j=0;j<i-1;j++){
                if(data[j]==i){
                    int tmp=data[j];
                    data[j]=data[j+1];
                    data[j+1]=tmp;
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
}
