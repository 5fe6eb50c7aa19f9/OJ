#include <iostream>
using namespace std;

int main()
{
    char password[4];
    while(cin>>password[0]>>password[1]>>password[2]>>password[3]){
        int num;
        cin>>num;
        for(;num>0;num--){
            int A=0,B=0;
            string tmpstr(password);
            char trY[4];
            cin>>trY[0]>>trY[1]>>trY[2]>>trY[3];
            for(int i=0;i<4;i++){
                if(tmpstr[i]==trY[i]){
                    tmpstr[i]='.';
                    trY[i]='.';
                    A++;
                }
            }
            for(int i=0;i<4;i++){
                if(trY[i]=='.')continue;
                int tmp=tmpstr.find(trY[i],0);
                if(tmp<7&&tmp>=0){
                    tmpstr[tmp]='.';
                    B++;
                }
            }
            cout<<A<<"A"<<B<<"B\n";
        }
    }
}

