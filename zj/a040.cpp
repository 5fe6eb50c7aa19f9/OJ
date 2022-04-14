#include <iostream>
using namespace std;
int sq(int a,int b){
    if(a==0){
        return 0;
    }
    if(b==0){
        return 1;
    }
    if(!b%2){
        return sq(a*a,b/2);
    }
    return a*sq(a,b-1);
}
int test(int a){
    int b=a;
    int resu=a;
    int n=0;
    while(b>0){
        b/=10;
        n++;
    }
    b=a;
    for(int i=n;i>0;i--){
        a-=sq(b%10,n);
        b/=10;
    }
    if(a==0){
        cout<<resu<<" ";
        return 1;
    }
    return 0;
}

int main()
{
    int a,b;
    while(cin>>a>>b){
        int tmp=0;
        for(;a<=b;a++){
            tmp+=test(a);
        }
        if(!tmp){
            cout<<"none";
        }
        cout<<endl;
    }
}
