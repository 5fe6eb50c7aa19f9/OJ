#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    string data;
    while(getline(cin,data)){
        int sum=0;
        for(int i=0;i<data.size();i++){
            if(data[i]!=' '){
                int tmp=0;
                bool flag=false;
                for(int j=i;j<data.size()&&data[j]!=' ';j++){
                    i=j;
                    if(!(data[j]>='0'&&data[j]<='9')||flag){
                        flag=true;
                        continue;
                    }
                    tmp*=10;
                    tmp+=data[j]-'0';
                }
                if(!flag)sum+=tmp;
            }
        }
        cout<<sum<<endl;
    }
}
