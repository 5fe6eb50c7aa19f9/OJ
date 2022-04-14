#include <iostream>
using namespace std;
string s1[105];
string s2[105];
int ans[105][105];
int pre[105][105];
int LCS(int l1,int l2){
    if(ans[l1][l2]!=-1){
        return ans[l1][l2];
    }
    if(s1[l1]!=s2[l2]){
        ans[l1][l2]=LCS(l1-1,l2);
        int tmp=LCS(l1,l2-1);
        if(ans[l1][l2]>=tmp){
            pre[l1][l2]=1;
        }else{
            ans[l1][l2]=tmp;
            pre[l1][l2]=2;
        }
    }else{
        ans[l1][l2]=LCS(l1-1,l2-1)+1;
        pre[l1][l2]=3;
    }
    return ans[l1][l2];
}
void travel(int l1,int l2,bool flag){//if exist a extra space,you will get WA
    if(l1==0||l2==0)return;
    switch(pre[l1][l2]){
        case 1:
            travel(l1-1,l2,flag);
            break;
        case 2:
            travel(l1,l2-1,flag);
            break;
        case 3:
            travel(l1-1,l2-1,true);
            cout<<s1[l1];
            if(flag){
                cout<<" ";
            }else{
                cout<<endl;
            }
            break;
    }
}
int main(){
    while(cin>>s1[1]){
        int n1=1;
        while(s1[n1]!="#"&&cin>>s1[n1+1]){
            n1++;
        }
        int n2=1;
        while(cin>>s2[n2]&&s2[n2]!="#"){
            n2++;
        }
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(i==0||j==0){
                    ans[i][j]=0;
                }else{
                    ans[i][j]=-1;
                }
            }
        }
        LCS(n1-1,n2-1);
        travel(n1-1,n2-1,false);
    }
}
