#include <iostream>
using namespace std;
#include <string>

int main()
{
    string a;
    while(getline(cin,a)){
        for(int i=0;i<a.size();i++){
            cout<<static_cast<char>(a[i]-7);
        }
        cout<<endl;
    }
    return 0;
}
