#include <iostream>
using namespace std;

int test(int a){
    if(a==1){
        return 2;
    }else if(a==0){
        return 1;
    }
    return test(a-1)*2-test(a-2)+a-1;
}
int main()
{
    int a;
    while(cin>>a){
        int tmp2=2;
        for(int i=2,tmp1=1;i<=a;i++){
            tmp1=tmp2*2-tmp1+i-1;
            int tmp=tmp1;
            tmp1=tmp2;
            tmp2=tmp;
        }
        cout<<tmp2<<endl;
    }
}
