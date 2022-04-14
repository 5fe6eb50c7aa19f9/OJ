#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

string day[7]={{"Sunday"},{"Monday"},{"Tuesday"},{"Wednesday"},{"Thursday"},{"Friday"},{"Saturday"}};
string month[13]={{""},{"January"},{"February"},{"March"},{"April"},{"May"},{"June"},{"July"},{"August"},{"September"},{"October"},{"November"},{"December"}};
int main(){
    int i,j,k,a,b,c,tot;
    int tmp;
    while(scanf("%d %d %d",&a,&b,&c)==3&&a+b+c){
        i=j=k=1,tot=6;
        if(c>=1753){
            tot=1;
            k=1753;
        }
        while(k<1752&&k<c){
            if(k%4==0)tot++;
            tot+=365;
            k++;
        }
        while(k>=1753&&k<c){
            if(k%4==0&&k%100!=0||k%400==0)tot++;
            tot+=365;
            k++;
        }
        for(;;j++,tot++){
            if(k==1752&&i==9&&j==3)j=14;
            if(k<=1752){
                if(i==2){
                    if(k%4==0&&j==30){
                        i++,j=1;
                    }else if(k%4!=0&&j==29){
                        i++,j=1;
                    }
                }else if(i<=7&&i%2==1||i>7&&i%2==0){
                    if(j==32){
                        i++,j=1;
                    }
                }else{
                    if(j==31){
                        i++,j=1;
                    }
                }
            }else{
                if(i==2){
                    if((k%4==0&&k%100!=0||k%400==0)&&j==30){
                        i++,j=1;
                    }else if(!(k%4==0&&k%100!=0||k%400==0)&&j==29){
                        i++,j=1;
                    }
                }else if(i<=7&&i%2==1||i>7&&i%2==0){
                    if(j==32){
                        i++,j=1;
                    }
                }else{
                    if(j==31){
                        i++,j=1;
                    }
                }
            }
            if(i==13)i=1,k++;
            if(i==a&&j==b&&k==c){
                cout<<month[i]<<" "<<j<<", "<<k<<" is a "<<day[tot%7]<<endl;
                break;
            }else if(k>c||k==c&&i>a||k==c&&i==a&&j>b){
                printf("%d/%d/%d is an invalid date.\n",a,b,c);
                break;
            }
        }
    }
}
