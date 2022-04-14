#include <iostream>
#include <cstdio>
#include <unordered_set>
using namespace std;
string data;
void recursive(int i){
    if(i==data.size()){
        for(i=data.size()-1;i>=0;i--)printf("%c",data[i]);
        printf("\n");
        return;
    }
    recursive(i+1);
    for(int j=i;j>=1;j--){
        swap(data[j],data[j-1]);
        recursive(i+1);
    }
    for(int j=0;j<i;j++){
        swap(data[j],data[j+1]);
    }
}
int main(){
    bool flag=0;
    while(getline(cin,data)){
        if(flag)printf("\n");
        flag=1;
        recursive(0);
    }
}
