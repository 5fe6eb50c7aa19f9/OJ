#include <iostream>
using namespace std;
#include <string>

int main()
{
    int a;
    while(cin>>a){
        if(a==1){
            cout<<1<<endl;
            continue;
        }
        int data[1000][2]={0};
        int num=0;
        for(int i=2,tmp=a;i<=a;i++){
            if(tmp%i==0){
                num++;
            }
            while(tmp%i==0){
                tmp/=i;
                data[num-1][0]=i;
                data[num-1][1]++;
            }
        }
        for(int i=0;i<num;i++){
            cout<<data[i][0];
            if(data[i][1]>1){
                cout<<"^"<<data[i][1];
            }
            if(i<num-1){
                cout<<" * ";
            }
        }
        cout<<endl;
    }
    return 0;
}
