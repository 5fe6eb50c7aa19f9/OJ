#include <iostream>
using namespace std;

int detect(int* start){
    int tmp[9];
    for(int i=0,k=0;i<27;i+=9){
        for(int j=0;j<3;j++){
            tmp[k]=*(start+i+j);
            k++;
        }
    }
    for(int i=0;i<8;i++){
        for(int j=i+1;j<9;j++){
            if(tmp[i]==tmp[j]){
                return 1;
            }
        }
    }

    return 0;
}
int main()
{
    int a[9][9];
    while(cin>>a[0][0]){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(i==0&&j==0){
                    continue;
                }
                cin>>a[i][j];
            }
        }
        int flag=0;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int tmp=a[i][j];
                for(int k=j+1;k<9;k++){
                    if(tmp==a[i][k]){
                        flag=1;
                    }
                    if(flag==1){
                        cout<<"no\n";
                        break;
                    }
                }
                if(flag==1){
                        break;
                    }
            }
            if(flag==1){
                        break;
                    }
        }
        if(flag==1){
            continue;
        }

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int tmp=a[j][i];
                for(int k=j+1;k<9;k++){
                    if(tmp==a[k][i]){
                        flag=1;
                    }
                    if(flag==1){
                        cout<<"no\n";
                        break;
                    }
                }
                if(flag==1){
                        break;
                    }
            }
            if(flag==1){
                        break;
                    }
        }
        if(flag==1){
            continue;
        }

        for(int i=0;i<=6;i+=3){
            for(int j=0;j<=6;j+=3){
                flag=detect(&a[i][j]);
                if(flag==1){
                    cout<<"no\n";
                    break;
                }
            }
            if(flag==1){
                break;
            }
        }
        if(flag==1){
            continue;
        }
        cout<<"yes\n";
    }
    return 0;
}
