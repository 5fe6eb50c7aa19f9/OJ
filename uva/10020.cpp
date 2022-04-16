#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

stringstream ss;
void doIO(){
    string tmp;
    getline(cin,tmp);
    ss.clear();
    ss.str(tmp);
}

struct Line{
    int l,r;
    bool operator<(const Line& o)const{
        if(l!=o.l)return l<o.l;
        return r>o.r;
    }
};

Line line[100005];
int res[100005];

int main(){
    int t;
    doIO();
    ss>>t;
    while(t--){
        int n,l,r,m;
        doIO();
        doIO();
        ss>>m;
        n=0;
        while(1){
            doIO();
            ss>>l>>r;
            if(l==0&&r==0)break;
            line[n++]={.l=l,.r=r};
        }

        sort(line,line+n);

        map<int,int> bt;
        int cur=0;
        int res_n=0;
        for(int i=0;i<n;++i){
            if(line[i].l<=cur){
                if(line[i].r>cur){
                    if(bt.find(line[i].r)==bt.end())bt[line[i].r]=i;
                }
            }else{
                if(bt.size()==0||cur>=m)break;
                int idx=bt.rbegin()->second; // idx of rightest line
                cur=line[idx].r;
                res[res_n++]=idx;
                bt.clear();
                i--;
            }
        }
        if(bt.size()&&cur<m){
            int idx=bt.rbegin()->second; // idx of rightest line
            cur=line[idx].r;
            res[res_n++]=idx;
        }

        if(cur<m)res_n=0;
        cout<<res_n<<"\n";
        for(int i=0;i<res_n;++i){
            int idx=res[i];
            cout<<line[idx].l<<" "<<line[idx].r<<"\n";
        }

        if(t)cout<<"\n";
    }
}

/*
2

1
-1 0
-5 -3
2 5
0 0

1
-1 0
0 1
0 0
*/
