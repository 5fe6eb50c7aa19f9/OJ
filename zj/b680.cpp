#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int go(int n){
    if(n==0)return 1;
    return 10*go(n-1);
}
int main(){
    int n;
    while(cin>>n){
        vector< pair<long long,int> > data(n);
        for(int i=0;i<n;i++){
            long long tmp1;
            string tmp2;
            int dot=7;
            bool flag=false;
            cin>>tmp1>>tmp2;
            data[i].second=tmp1;
            tmp1=0;
            for(int j=0;j<tmp2.size();j++){
                if(tmp2[j]=='.'){
                    flag=true;
                    continue;
                }
                if(flag)dot--;
                tmp1*=10;
                tmp1+=tmp2[j]-'0';
            }
            data[i].first=tmp1*go(dot);
        }
        sort(data.begin(),data.end());
        int tmp[n/8][8];
        int num=0,x=0;
        while(true){
            if(num>=n)break;
            for(int i=0;i<n/8;i++){
                tmp[i][x]=data[num].second;
                num++;
            }
            x++;
            for(int i=n/8-1;i>=0;i--){
                tmp[i][x]=data[num].second;
                num++;
            }
            x++;
        }
        for(int i=0;i<n/8;i++){
            cout<<i+1<<' '<<tmp[i][6]<<' '<<tmp[i][4]<<' '<<tmp[i][2]<<' '<<tmp[i][0]<<' '<<tmp[i][1]<<' '<<tmp[i][3]<<' '<<tmp[i][5]<<' '<<tmp[i][7]<<endl;
        }
    }
}
