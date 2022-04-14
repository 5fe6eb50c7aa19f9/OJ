#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
string data;
void sol(int i){
    int j;
    for(j=data.size()-1;j>i;j--){
        if(data[i]<data[j]){
            swap(data[i],data[j]);
            break;
        }
    }
    for(i=i+1,j=data.size()-1;i<j;i++,j--){
        swap(data[i],data[j]);
    }
}
int main(){
    int i,j;
    while(cin>>data&&data!="#"){
        if(data.size()==1){
            printf("No Successor\n");
            continue;
        }
        for(i=data.size()-2;i>=0;i--){
            if(data[i]<data[i+1]){
                sol(i);
                cout<<data<<endl;
                break;
            }
            if(i==0){
                printf("No Successor\n");
            }
        }
    }
}
