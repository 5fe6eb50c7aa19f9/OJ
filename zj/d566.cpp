#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        cin.ignore();
        string data[n][2];
        bool test[n]={false};
        int p=0,sum=0;
        for(int i=0;i<n;i++){
            bool ju=false;
            string tmp1,tmp2;
            cin>>tmp1>>tmp2;
            for(int j=i-1;j>=0;j--){
                if(data[j][0]==tmp1){
                    ju=true;
                    if(tmp2=="AC"&&!test[j]){
                        test[j]=true;
                        p++;
                    }
                    data[j][1]=tmp2;
                    break;
                }
            }
            if(!ju){
                data[i][0]=tmp1;
                data[i][1]=tmp2;
                if(tmp2=="AC"){
                    p++;
                    test[i]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(data[i][1]=="AC")sum++;
        }
        cout<<sum*100/p<<'%'<<endl;
    }
}
