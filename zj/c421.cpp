#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;
char buf[50000000];
int data[1000000];
multiset<int> s;
multiset<int>::iterator it;
int main(){
    int n,i,j,k;
    scanf("%[^\n]",buf);
    for(i=0,j=0,k=0,n=0;buf[i];i++){
        if(buf[i]>='0'&&buf[i]<='9'){
            j=j*10+buf[i]-'0';
        }else if(buf[i]=='-'){
            k=1;
        }else{
            if(k)j*=-1;
            data[n++]=j;
            j=k=0;
        }
    }
    for(i=0;i<n;i++){
        if(data[i]==-2&&s.size()){
            it=s.end();
            it--;
            printf("%d ",*it);
            s.erase(it);
        }else if(data[i]==-1&&s.size()){
            it=s.begin();
            printf("%d ",*it);
            s.erase(it);
        }else if(data[i]>0){
            s.insert(data[i]);
        }
    }
}
