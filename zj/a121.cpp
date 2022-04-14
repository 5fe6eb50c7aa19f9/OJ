#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a,b;
    while(cin>>a>>b){
        int sum=0;
        for(;a<=b;a++){
            if(a==1){
                continue;
            }
            for(int i=2;;i++){
                if(i>sqrt(a)||i==a){
                    sum++;
                    break;
                }
                if(a%i==0){
                    break;
                }
            }
        }
        cout<<sum<<endl;
    }
}
