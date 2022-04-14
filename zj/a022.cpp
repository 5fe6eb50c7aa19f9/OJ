#include <iostream>
using namespace std;

int main()
{
    string a;
    while(cin>>a){
        for(int i=0,j=a.size()-1;;i++,j--){
            if(i-1==(a.size())/2){
                cout<<"yes\n";
                break;
            }
            if(a[i]!=a[j]){
                cout<<"no\n";
                break;
            }
        }
    }
    return 0;
}
