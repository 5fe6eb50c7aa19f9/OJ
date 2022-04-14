#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        string data[n];
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp>>tmp;
            for(int j=0,num;j<tmp;j++){
                cin>>num;
                data[i]+=" ";
                do{
                    data[i]+=num%10+'0';
                    num/=10;
                }while(num>0);
                data[i]+=" ";
            }
        }
        int tmp;
        cin>>tmp;
        string stmp;
        stmp+=" ";
        do{
            stmp+=tmp%10+'0';
            tmp/=10;
        }while(tmp>0);
        stmp+=" ";

        for(int i=0;i<n;i++){
            tmp=data[i].find(stmp,0);
            if(tmp>=0&&tmp<data[i].size()){
                cout<<i+1<<endl;
                break;
            }
        }
    }
}
