#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int data[26];
bool judge(){
    if(data[6]!=0&&data[1]!=0){if(data[6]-1!=data[1])return false;}//1
    if(data[7]!=0&&data[21]!=0){if(data[7]+3!=data[21])return false;}//2
    if(data[8]!=0&&data[11]!=0){if(data[8]+1!=data[11])return false;}//3
    if(data[2]!=0&&data[3]!=0){if(data[2]+5!=data[3])return false;}//4 left?
    if(data[2]!=0&&data[12]!=0){if(data[2]+2!=data[12])return false;}//5
    if(data[16]!=0&&data[22]!=0){if(data[16]+1!=data[22])return false;}//6
    if(data[4]!=0&&data[20]!=0){if(data[4]+3!=data[20])return false;}//7
    if(data[13]!=0){if(data[13]!=13)return false;}//8
    if(data[9]!=0){if(data[9]!=2)return false;}//9
    if(data[17]!=0&&data[23]!=0){if((data[17]>data[23]&&data[17]-data[23]!=4)||(data[23]>data[17]&&data[23]-data[17]!=6))return false;}//10
    if(data[24]!=0&&data[20]!=0){if((data[24]>data[20]&&data[24]-data[20]!=6)||(data[20]>data[24]&&data[20]-data[24]!=4))return false;}//11
    if(data[14]!=0&&data[18]!=0){if(data[14]+1!=data[18])return false;}//12
    if(data[10]!=0&&data[19]!=0){if(data[10]+2!=data[19])return false;}//13
    if(data[9]!=0&&data[5]!=0){if((data[9]>data[5]&&data[9]-data[5]!=6)||(data[5]>data[9]&&data[5]-data[9]!=4))return false;}//14
    if(data[17]!=0&&data[15]!=0){if((data[17]>data[15]&&data[17]-data[15]!=6)||(data[15]>data[17]&&data[15]-data[17]!=4))return false;}//15
    return true;
}
void goc(int r);
void gon(int r);
void god(int r);
void goci(int r);
void gop(int r);

int main(){
    for(int i=0;i<26;i++)data[i]=0;
    goc(0);
}

void goc(int r){
    if(r==5){
        int gr[25];
        for(int i=1;i<=25;i++)gr[data[i]]=i;
        printf("     House     Color    Nation     Drink Cigarette       Pet\n");
        for(int i=1;i<=25;i+=5){
            printf("        H%d%10d%10d%10d%10d%10d\n",i/5+1,gr[i],gr[i+1],gr[i+2],gr[i+3],gr[i+4]);
        }
        return;
    }
    for(int i=1;i<=5;i++){
        if(data[i]==0){
            data[i]=5*r+1;
            if(!judge()){
                data[i]=0;
                continue;
            }
            gon(r);
            data[i]=0;
        }
    }
}
void gon(int r){
    for(int i=6;i<=10;i++){
        if(data[i]==0){
            data[i]=5*r+2;
            if(!judge()){
                data[i]=0;
                continue;
            }
            god(r);
            data[i]=0;
        }
    }
}
void god(int r){
    for(int i=11;i<=15;i++){
        if(data[i]==0){
            data[i]=5*r+3;
            if(!judge()){
                data[i]=0;
                continue;
            }
            goci(r);
            data[i]=0;
        }
    }
}
void goci(int r){
    for(int i=16;i<=20;i++){
        if(data[i]==0){
            data[i]=5*r+4;
            if(!judge()){
                data[i]=0;
                continue;
            }
            gop(r);
            data[i]=0;
        }
    }
}
void gop(int r){
    for(int i=21;i<=25;i++){
        if(data[i]==0){
            data[i]=5*r+5;
            if(!judge()){
                data[i]=0;
                continue;
            }
            goc(r+1);
            data[i]=0;
        }
    }
}
