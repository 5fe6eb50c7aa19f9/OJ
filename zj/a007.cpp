#include <iostream>
using namespace std;
const int psize=46350;
bool prime[psize]={false};//false is prime;true isnt prime

int main(){
    int fprime[psize]={2};
    int fps=1;
    for(int i=2;i<psize;i++){
        if(prime[i])continue;
        for(int j=i*i;j<=psize;j+=i){
            prime[j]=true;
        }
        fprime[fps]=i;
        fps++;
    }
    int a;
    while(cin>>a){
        bool flag=false;
        if(a<psize){
            cout<<((prime[a])?"N\n":"Y\n");
            continue;
        }
        for(int i=0;i<fps;i++){
            if(a%fprime[i]==0){
                flag=true;
                break;
            }
        }
        if(!flag){
            cout<<"Y\n";
        }else{
            cout<<"N\n";
        }
    }
}
