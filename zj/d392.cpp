#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int main(){
    string n;
    while(getline(cin,n)){
        int sum=0;
        for(int i=0;i<n.size();i++){
            if(n[i]==' ')continue;
            int tmp=0;
            for(int j=i;j<n.size()&&n[j]!=' ';j++){
                tmp*=10;
                tmp+=n[j]-'0';
                i=j;
            }
            sum+=tmp;
        }
        cout<<sum<<endl;
    }
}
