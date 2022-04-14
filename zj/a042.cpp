#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n){
        if(n<3){
            cout<<2*n<<endl;
        }else{
            cout<<2*n+(n-2+1)*(n-2)<<endl;
        }
    }
    return 0;
}
