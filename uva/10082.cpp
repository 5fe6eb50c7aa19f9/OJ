#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

string data;
char delta[128];
int main(){
    int i;
    delta['1']='`';
    delta['2']='1';
    delta['3']='2';
    delta['4']='3';
    delta['5']='4';
    delta['6']='5';
    delta['7']='6';
    delta['8']='7';
    delta['9']='8';
    delta['0']='9';
    delta['-']='0';
    delta['=']='-';
    delta['W']='Q';
    delta['E']='W';
    delta['R']='E';
    delta['T']='R';
    delta['Y']='T';
    delta['U']='Y';
    delta['I']='U';
    delta['O']='I';
    delta['P']='O';
    delta['[']='P';
    delta[']']='[';
    delta['\\']=']';
    delta['S']='A';
    delta['D']='S';
    delta['F']='D';
    delta['G']='F';
    delta['H']='G';
    delta['J']='H';
    delta['K']='J';
    delta['L']='K';
    delta[';']='L';
    delta['\'']=';';
    delta['X']='Z';
    delta['C']='X';
    delta['V']='C';
    delta['B']='V';
    delta['N']='B';
    delta['M']='N';
    delta[',']='M';
    delta['.']=',';
    delta['/']='.';
    while(getline(cin,data)){
        for(i=0;i<data.size();i++){
            if(data[i]!=' '){
                data[i]=delta[data[i]];
            }
        }
        cout<<data<<endl;
    }
}
