#include <iostream>
using namespace std;

int main()
{
    int a;
    while(cin>>a){
        int flag=a%10;
        a/=10;
        int sum=0;
        for(int i=1;i<=8;i++){
            sum+=(a%10)*i;
            a/=10;
        }
        if((0+sum+flag)%10==0){
            cout<<"BNZ"<<endl;
        }else if((1+sum+flag)%10==0){
            cout<<"AMW"<<endl;
        }else if((2+sum+flag)%10==0){
            cout<<"KLY"<<endl;
        }else if((3+sum+flag)%10==0){
            cout<<"JVX"<<endl;
        }else if((4+sum+flag)%10==0){
            cout<<"HU"<<endl;
        }else if((5+sum+flag)%10==0){
            cout<<"GT"<<endl;
        }else if((6+sum+flag)%10==0){
            cout<<"FS"<<endl;
        }else if((7+sum+flag)%10==0){
            cout<<"ER"<<endl;
        }else if((8+sum+flag)%10==0){
            cout<<"DOQ"<<endl;
        }else if((9+sum+flag)%10==0){
            cout<<"CIP"<<endl;
        }
//(sum+a+b*10)%10+flag=10
//0 BNZ//
//1 AMW
//2 KLY
//3 JVX
//4 HU
//5 GT//
//6 FS
//7 ER
//8 DOQ
//9 CIP
    }
}
