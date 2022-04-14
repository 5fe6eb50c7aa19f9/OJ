#include <iostream>
using namespace std;

int main()
{
    char a;
    int b;
    while(cin>>a>>b){
        if(a<='H'){
            a-=55;
        }else if(a=='I'){
            a=34;
        }else if(a<='N'){
            a-=56;
        }else if(a=='O'){
            a=35;
        }else if(a<='V'){
            a-=57;
        }else if(a=='W'){
            a=32;
        }else if(a<='Y'){
            a-=58;
        }else{
            a=33;
        }
        int sum=(int)a/10+((int)a%10)*9;
        sum+=b%10;
        b/=10;
        for(int i=1;i<9;i++){
            sum+=(b%10)*i;
            b/=10;
        }
        cout<<sum;
        if(sum%10==0){
            cout<<"real"<<endl;
        }else{
            cout<<"fake"<<endl;
        }
    }
    return 0;
}
