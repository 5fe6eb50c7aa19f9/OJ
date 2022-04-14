#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string d;
    while(cin>>d){
        vector<int> da;
        for(int i=0;i<d.size();i++){
            if((d[i]>='a'&&d[i]<='z')||(d[i]>='A'&&d[i]<='Z')){
                if(d[i]>=97&&d[i]<=122)d[i]-=32;
                da.push_back(d[i]);
            }
        }
        sort(da.begin(),da.end());
        bool flag=true;
        if((da.end()-da.begin())%2==0){
            for(int i=0;i<da.end()-da.begin();i+=2){
                if(da[i]!=da[i+1]){
                    flag=false;
                    break;
                }
            }
        }else{
            for(int i=0,f=0;i<da.end()-da.begin();){
                if(da[i]==da[i+1]){
                    i+=2;
                }else if(da[i]!=da[i+1]){
                    if(f==1){
                        flag=false;
                        break;
                    }
                    i++;
                    f=1;
                }
            }
        }
        if(flag){
            cout<<"yes !\n";
        }else{
            cout<<"no...\n";
        }
    }
}
