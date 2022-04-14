#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

string data;
char tmp;
bool go(){
    stack<char> s;
    for(int i=0;i<data.size();i++){
        switch(data[i]){
            case '(':
                s.push('(');
                break;
            case '[':
                s.push('[');
                break;
            case ')':
                if(!s.empty()&&s.top()=='('){
                    s.pop();
                }else{
                    return 0;
                }
                break;
            case ']':
                if(!s.empty()&&s.top()=='['){
                    s.pop();
                }else{
                    return 0;
                }
                break;
        }
    }
    if(!s.empty())return 0;
    return 1;
}
int main(){
    int n,i;
    scanf("%d",&n);
    scanf("%c",&tmp);
    while(n--){
        getline(cin,data);
        if(data.size()==0){
            printf("Yes\n");
            continue;
        }
        if(go()){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}
