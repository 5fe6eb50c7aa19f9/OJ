#include <iostream>
using namespace std;

int mod(int* x,int* y,int rate,int lenghth,int lenghth2){
    if(rate==-1){
        return 0;
    }
    for(int sum=0;;sum++){
        for(int i=0;i<lenghth2;){
            if(*(x+lenghth2+rate-1-i)>*(y+lenghth2-1-i)){
                break;
            }else if(*(x+lenghth2+rate-1-i)==*(y+lenghth2-1-i)){
                i++;
            }else if(*(x+lenghth2+rate-1-i)<*(y+lenghth2-1-i)){
                cout<<sum;
                return mod(x,y,rate-1,lenghth,lenghth2);
            }
        }
        for(int i=0;i<lenghth2;i++){
            *(x+i+rate)-=*(y+i);
            if(*(x+i+rate)<0){
                *(x+i+rate)+=10;
                *(x+i+rate+1)-=1;
            }
        }
        int flag=1;
        for(int i=0;i<lenghth;i++){
            if(*(x+i)!=0){
                flag=0;
                break;
            }
        }
        if(flag==1){
            cout<<sum+1;
            return mod(x,y,rate-1,lenghth,lenghth2);
        }
    }
}
int main()
{
    string a,b;
    char op;
    while(cin>>a>>op>>b){
        int x[501]={0};
        int y[501]={0};
        int z[501]={0};
        if(a.size()<b.size()||(a.size()==b.size()&&a[0]<b[0])){
            string tmp=a;
            a=b;
            b=tmp;
            if(op=='/'){
                cout<<"0\n";
                continue;
            }else if(op=='-'){
                cout<<op;
            }
        }
        for(int i=0;i<a.size();i++){
            x[i]=(int)a[a.size()-1-i]-48;
        }
        for(int i=0;i<b.size();i++){
            y[i]=(int)b[b.size()-1-i]-48;
        }
        switch(op){
            case '+':
                for(int i=0;i<a.size();i++){
                    x[i]+=y[i];
                    if(x[i]>9){
                        x[i]-=10;
                        x[i+1]++;
                    }
                }
                break;
            case '-':
                for(int i=0;i<a.size();i++){
                    x[i]-=y[i];
                    if(x[i]<0){
                        x[i]+=10;
                        x[i+1]--;
                    }
                }
                break;
            case '*':
                if(b.size()==1&&b[0]=='1'){
                    cout<<a<<endl;
                    op='/';
                    break;
                }
                for(int j=0;j<b.size();j++){
                    for(int i=0;i<a.size();i++){
                        z[j+i]+=y[j]*x[i];
                        while(z[j+i]>9){
                            z[j+i]-=10;
                            z[j+i+1]++;
                        }
                    }
                }
                for(int i=500,flag=0;i>=0;i--){
                    if(flag==0&&z[i]!=0){
                        flag=1;
                    }
                    if(flag==1){
                        cout<<z[i];
                    }
                }
                cout<<endl;
                op='/';
                break;
            case '/':
                //
                int rate=0,sum=0;
                rate=a.size()-b.size();
                mod(x,y,rate,a.size(),b.size());
                cout<<endl;
                //
                break;
        }
        if(op=='/'){
            continue;
        }
        for(int i=500,flag=0;i>=0;i--){
            if(flag==0&&x[i]!=0){
                flag=1;
            }
            if(flag==1){
                cout<<x[i];
            }
        }
        cout<<endl;
    }
}
