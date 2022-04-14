#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a;
    while(cin>>a){
        int data[a];
        for(int i=a;i>0;i--){
            data[a-i]=i;
        }
        for(int j=0;j<a;j++){
            cout<<data[j];
        }
        cout<<endl;
        for(int flag=a-1;flag>0;flag--){
            if(data[flag-1]>data[flag]){
                for(int i=a-1;i>=0;i--){
                    if(data[flag-1]>data[i]){
                        int tmp=data[i];
                        data[i]=data[flag-1];
                        data[flag-1]=tmp;
                        for(int pre=flag,later=a-1;pre<=(pre+later)/2;pre++,later--){
                            tmp=data[pre];
                            data[pre]=data[later];
                            data[later]=tmp;
                        }
                        flag=a;
                        break;
                    }
                }
                for(int j=0;j<a;j++){
                    cout<<data[j];
                }
                cout<<endl;
            }
        }
    }
}
