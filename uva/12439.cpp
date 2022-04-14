#include <iostream>
#include <cstdio>
#include <unordered_set>
using namespace std;
string month[12]= {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};
int main(){
    int t,T,i,j,ans;
    int a[3];
    int b[3];
    string tmp;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        cin>>tmp;
        for(i=0;i<12;i++){
            if(tmp==month[i]){
                a[0]=i+1;
                break;
            }
        }
        scanf("%d",a+1);
        cin>>tmp;
        scanf("%d",a+2);
        cin>>tmp;
        for(i=0;i<12;i++){
            if(tmp==month[i]){
                b[0]=i+1;
                break;
            }
        }
        scanf("%d",b+1);
        cin>>tmp;
        scanf("%d",b+2);
        ans=0;
        if(b[2]-a[2]>=2){
            ans+=(b[2]-1)/4-(a[2]+1)/4+((a[2]+1)%4==0);
            ans-=(b[2]-1)/100-(a[2]+1)/100+((a[2]+1)%100==0);
            ans+=(b[2]-1)/400-(a[2]+1)/400+((a[2]+1)%400==0);
        }
        if((a[2]%4==0&&a[2]%100!=0)||(a[2]%400==0)){
            if(a[0]<2||(a[0]==2&&a[1]<=29)){
                ans++;
                if((a[2]==b[2])&&(b[0]<2||(b[0]==2&&b[1]<29)))ans--;
            }
        }
        if((b[2]%4==0&&b[2]%100!=0)||(b[2]%400==0)){
            if(b[0]>2||(b[0]==2&&b[1]==29)){
                if(a[2]!=b[2])ans++;
            }
        }
        printf("Case %d: %d\n",t,ans);
    }
}
