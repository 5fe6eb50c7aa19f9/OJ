#include <iostream>
using namespace std;

string a;
bool comput(int START,int END){
    int data[100]={0};
    int num=0;
    for(int i=END;i>=START;i--){
        int rate=1;
        while(a[i]>=48&&a[i]<=57&&i>=START){
            data[num]+=(a[i]-48)*rate;
            a[i]=' ';
            rate*=10;
            i--;
        }
        if(rate!=1){
            if(i>=0&&a[i]=='-'){
                a[i]='x';
                a[i+1]=' ';
                data[num]*=-1;
            }else{
                a[i+1]='x';
            }
            num++;
        }
    }
    for(int i=0;i<num/2;i++){
        int tmp=data[i];
        data[i]=data[num-1-i];
        data[num-1-i]=tmp;
    }
    for(int i=START,j=0;i<=END;i++){
        if(a[i]=='x'||a[i]=='y'){
            j++;
        }
        if(a[i]=='%'){
            for(int k=i-1,l=j-1;;k--){
                if(a[k]=='y'){
                    l--;
                }
                if(a[k]=='x'){
                    data[l]%=data[j];
                    a[i]=' ';
                    a[i+2]='y';
                    break;
                }
            }
        }
    }
    for(int i=START,j=0;i<=END;i++){
        if(a[i]=='x'||a[i]=='y'){
            j++;
        }
        if(a[i]=='*'||a[i]=='/'){
            for(int k=i-1,l=j-1;;k--){
                if(a[k]=='y'){
                    l--;
                }
                if(a[k]=='x'){
                    data[l]=(a[i]=='*')?data[l]*data[j]:data[l]/data[j];
                    a[i]=' ';
                    a[i+2]='y';
                    break;
                }
            }
        }
    }
    for(int i=START,j=0;i<=END;i++){
        if(a[i]=='x'||a[i]=='y'){
            j++;
        }
        if(a[i]=='+'||a[i]=='-'){
            for(int k=i-1,l=j-1;;k--){
                if(a[k]=='y'){
                    l--;
                }
                if(a[k]=='x'){
                    data[l]=(a[i]=='+')?data[l]+data[j]:data[l]-data[j];
                    a[i]=' ';
                    a[i+2]='y';
                    break;
                }
            }
        }
    }
    a.erase(START,END-START+1);
    string Result;
    if(data[0]==0){
        Result+='0';
    }
    if(data[0]<0){
        data[0]*=-1;
        Result+='-';
    }
    for(int i=0;data[0]>0;){
        if(Result[0]=='-'){
            i=1;
        }
        string tmpstr;
        tmpstr+=data[0]%10+48;
        Result.insert(i,tmpstr);
        data[0]/=10;
    }
    a.insert(START,Result);//c * ( a + b )
    if(a.size()==Result.size()){
        cout<<a<<endl;
        return true;
    }
    return false;
}
int main()
{
    while(getline(cin,a)){
        int START,END;
        while(1){
            for(START=a.size()-1;;START--){
                if(a[START]=='('||START==0)
                    break;
            }
            for(END=START;;END++){
                if(a[END]==')'||END==a.size()-1)
                    break;
            }
            if(comput(START,END)){
                break;
            }
        }
    }
}
