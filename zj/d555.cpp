#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n,casE=0;
    while(cin>>n){
        vector< pair<int,int> > data;
        vector< pair<int,int> > ans;
        int sum=0;
        for(int i=0,x,y;i<n;i++){
            cin>>x>>y;
            data.push_back(make_pair(y,x));
        }
        sort(data.begin(),data.end());
        for(int i=n-1,lim=-1;i>=0;i--){
            int rr=i;
            for(int j=i-1;j>=0;j--){
                if(j==0||data[j].first!=data[rr].first){
                    if(data[j].first!=data[rr].first)i=j+1;
                    else i=j;
                    break;
                }
                if(data[rr].second<data[j].second){
                    rr=j;
                }
            }
            if(data[rr].second>lim){
                ans.push_back(make_pair(data[rr].second,data[rr].first));
                sum++;
                lim=data[rr].second;
            }
        }
        casE++;
        cout<<"Case "<<casE<<":\n"<<"Dominate Point: "<<sum<<endl;
        for(int i=0;i<sum;i++)cout<<'('<<ans[i].first<<','<<ans[i].second<<')'<<endl;
    }
}
