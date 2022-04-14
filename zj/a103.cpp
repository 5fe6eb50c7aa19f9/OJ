#include <iostream>
using namespace std;
#include <string>

int trans(string a){
    int b[a.size()];
    int sum=0;
    for(int i=0;i<a.size();i++){
        switch(a[i]){
            case 'I':b[i]=1;break;
            case 'V':b[i]=5;break;
            case 'X':b[i]=10;break;
            case 'L':b[i]=50;break;
            case 'C':b[i]=100;break;
            case 'D':b[i]=500;break;
            case 'M':b[i]=1000;break;
        }
        if(i>0&&b[i-1]<b[i]){
            b[i-1]*=-1;
        }
    }
    for(int i=0;i<a.size();i++){
        sum+=b[i];
    }
    return sum;
}
int main()
{
    string a[2];
    while(cin>>a[0]){
        if(a[0]=="#"){
            break;
        }
        cin>>a[1];
        int sum;
        sum=trans(a[0])-trans(a[1]);
        if(sum<0){
            sum*=-1;
        }else if(sum==0){
            cout<<"ZERO"<<endl;
            continue;
        }
        for(;sum>=1000;sum-=1000){
            cout<<"M";
        }
        if(sum>=900){
            cout<<"CM";
            sum-=900;
        }
        if(sum>=500){
            cout<<"D";
            sum-=500;
        }
        if(sum>=400){
            cout<<"CD";
            sum-=400;
        }
        for(;sum>=100;sum-=100){
            cout<<"C";
        }
        if(sum>=90){
            cout<<"XC";
            sum-=90;
        }
        if(sum>=50){
            cout<<"L";
            sum-=50;
        }
        if(sum>=40){
            cout<<"XL";
            sum-=40;
        }
        for(;sum>=10;sum-=10){
            cout<<"X";
        }
        if(sum==9){
            cout<<"IX";
            sum-=9;
        }
        if(sum>=5){
            cout<<"V";
            sum-=5;
        }
        if(sum>=4){
            cout<<"IV";
            sum-=4;
        }
        for(;sum>=1;sum-=1){
            cout<<"I";
        }
        cout<<endl;
    }
    return 0;
}
