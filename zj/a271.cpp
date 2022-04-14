#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int num;
    while(scanf("%d",&num)==1){
        for(;num>0;num--){
            int x,y,z,w,n,m;
            string day;
            //1.red+x;2.white+y;3.yellow-z;4.black-w&-n/day;m=origin weight
            scanf("%d %d %d %d %d %d",&x,&y,&z,&w,&n,&m);
            cin.ignore();
            getline(cin,day);
            if(day.size()==0){
                printf("%dg\n",m);
                continue;
            }
            for(int i=0,poison=0;i<day.size();i+=2){
                m-=n*poison;
                if(m<=0){
                    printf("bye~Rabbit\n");
                    break;
                }
                switch(day[i]-48){
                    case 1:m+=x;break;
                    case 2:m+=y;break;
                    case 3:m-=z;break;
                    case 4:m-=w;poison++;break;
                    case 0:break;
                }
                if(m<=0){
                    printf("bye~Rabbit\n");
                    break;
                }
            }
            if(m>0){
                printf("%dg\n",m);
            }
        }
    }
}

