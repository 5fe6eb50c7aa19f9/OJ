#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a;
    while(cin>>a){
        int data[a][2];
        for(int i=0;i<a;i++){
            cin>>data[i][0]>>data[i][1];
        }
        for(int i=0;i<a;i++){
            int tmp=(data[i][1]-data[i][0])*100000/data[i][0];
            int kord=tmp;
            int flag=0;
            if(tmp<0){
                tmp*=-1;
                flag++;
            }
            if(tmp%10>4){
                tmp=tmp+10;
            }
            tmp/=10;
            char res[6]={'0','0','0','.','0','0'};
            for(int i=5,tmp2=tmp;;i--){
                if(i==3){
                    continue;
                }
                res[i]+=tmp2%10;
                tmp2/=10;
                if(tmp2==0&&i<=2){
                    if(flag){
                        res[i-1]='-';
                        tmp*=-1;
                    }
                    for(int j=0;;j++){
                        if(res[j]!='0'||j==2){
                            for(int k=j;k<6;k++){cout<<res[k];}
                            break;
                        }else{
                            cout<<" ";
                        }
                    }
                    break;
                }
            }
            if(kord>=10000||kord<=-7000){
                cout<<"% dispose\n";
            }else{
                cout<<"% keep\n";
            }
        }
    }
}
