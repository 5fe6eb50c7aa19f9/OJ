#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
int data[26];
int main()
{
    data['B'-'A']=1;
    data['P'-'A']=1;
    data['F'-'A']=1;
    data['V'-'A']=1;
    data['C'-'A']=2;
    data['S'-'A']=2;
    data['K'-'A']=2;
    data['G'-'A']=2;
    data['J'-'A']=2;
    data['Q'-'A']=2;
    data['X'-'A']=2;
    data['Z'-'A']=2;
    data['D'-'A']=3;
    data['T'-'A']=3;
    data['L'-'A']=4;
    data['M'-'A']=5;
    data['N'-'A']=5;
    data['R'-'A']=6;
    cout<<"NAME                     SOUNDEX CODE\n";
    string tmp;
    while(cin>>tmp){
        int flag=0;
        cout<<"         "<<tmp;
        for(int i=9+tmp.size()+1;i<=34;i++)cout<<' ';
        cout<<tmp[0];
        for(int i=1;i<tmp.size()&&flag<3;i++){
            if(data[tmp[i]-'A']!=0&&data[tmp[i]-'A']!=data[tmp[i-1]-'A']){
                cout<<data[tmp[i]-'A'];
                flag++;
            }
        }
        for(int i=flag;i<3;i++)cout<<'0';
        cout<<endl;
    }
    cout<<"                   END OF OUTPUT\n";
}
