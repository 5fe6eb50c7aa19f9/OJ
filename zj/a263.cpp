#include <iostream>
using namespace std;

int date[2][3]={0};//y,m,d
void sum(int num){
    for(int i=1;i<date[num][0];i++){
        if((i%400==0&&i%4000!=0)||(i%100!=0&&i%4==0)){
            date[num][2]+=366;
        }else{
            date[num][2]+=365;
        }
    }
    for(int i=1;i<date[num][1];i++){
        if(i==2){
            date[num][2]+=(((date[num][0]%400==0&&date[num][0]%4000!=0)||(date[num][0]%100!=0&&date[num][0]%4==0))?29:28);
        }else if((i<8&&i%2==1)||(i>=8&&i%2==0)){
            date[num][2]+=31;
        }else{
            date[num][2]+=30;
        }
    }
    return;
}
int main(){
    while(cin>>date[0][0]>>date[0][1]>>date[0][2]>>date[1][0]>>date[1][1]>>date[1][2]){
        sum(0);
        sum(1);
        cout<<(date[0][2]>date[1][2]?date[0][2]-date[1][2]:date[1][2]-date[0][2])<<endl;
    }
}

