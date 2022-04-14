#include <iostream>
#include <algorithm>
using namespace std;

string card[10];
int tmp[5];
int cnt[14];
int sol(int i,int j){
    if(i==5){
        int st=0,fl=0,d=0,t=0;
        for(i=0;i<5;i++)tmp[i]=card[i][0];
        sort(tmp,tmp+5);
        for(i=1;;i++){
            if(i==1&&tmp[0]==1&&tmp[1]==10)continue;
            if(tmp[i]!=tmp[i-1]+1)break;
            if(i==4){
                st=1;
                break;
            }
        }
        for(i=1;;i++){
            if(card[i][1]!=card[i-1][1])break;
            if(i==4){
                fl=1;
                break;
            }
        }
        if(st&&fl)return 0;
        for(i=1;i<=13;i++)cnt[i]=0;
        for(i=0;i<5;i++){
            cnt[card[i][0]]++;
            if(cnt[card[i][0]]==4)return 1;
        }
        for(i=1,j=0;i<=13;i++){
            if(cnt[i]==2)d++;
            if(cnt[i]==3)t++;
        }
        if(d&&t)return 2;
        if(fl)return 3;
        if(st)return 4;
        if(t)return 5;
        if(d==2)return 6;
        if(d)return 7;
        return 8;
    }
    int ret=10;
    ret=min(ret,sol(i+1,j));
    swap(card[i],card[j]);
    ret=min(ret,sol(i+1,j+1));
    swap(card[i],card[j]);
    return ret;
}
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int i,j,k,ans;
    while(cin>>card[0]){
        cout<<"Hand: "<<card[0]<<" ";
        switch(card[0][0]){
            case 'A':card[0][0]=1;break;
            case 'T':card[0][0]=10;break;
            case 'J':card[0][0]=11;break;
            case 'Q':card[0][0]=12;break;
            case 'K':card[0][0]=13;break;
            default:card[0][0]-='0';
        }
        for(i=1;i<10;i++){
            if(i==5)cout<<"Deck: ";
            cin>>card[i];
            cout<<card[i]<<" ";
            switch(card[i][0]){
                case 'A':card[i][0]=1;break;
                case 'T':card[i][0]=10;break;
                case 'J':card[i][0]=11;break;
                case 'Q':card[i][0]=12;break;
                case 'K':card[i][0]=13;break;
                default:card[i][0]-='0';
            }
        }
        ans=sol(0,5);
        cout<<"Best hand: ";
        switch(ans){
            case 0:cout<<"straight-flush\n";break;
            case 1:cout<<"four-of-a-kind\n";break;
            case 2:cout<<"full-house\n";break;
            case 3:cout<<"flush\n";break;
            case 4:cout<<"straight\n";break;
            case 5:cout<<"three-of-a-kind\n";break;
            case 6:cout<<"two-pairs\n";break;
            case 7:cout<<"one-pair\n";break;
            case 8:cout<<"highest-card\n";break;
        }
    }
}
