#include <cstdio>
#include <iostream>
using namespace std;

int KMP[1000000];
string data;
int main(){
    int i,j;
    KMP[0]=-1;
    while(getline(cin,data)&&data!="."){
        for(i=1,j=-1;i<data.size();i++){
            while(j!=-1&&data[i]!=data[j+1]){
                j=KMP[j];
            }
            if(data[i]==data[j+1])j++;
            KMP[i]=j;
        }
        if(data.size()%(data.size()-KMP[data.size()-1]-1)==0){
            printf("%d\n",data.size()/(data.size()-KMP[data.size()-1]-1));
        }else{
            printf("1\n");
        }
    }
}
